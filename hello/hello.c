#include <linux/init.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/uaccess.h>

#define PROC_NAME "hello_proc"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Mert");
MODULE_DESCRIPTION("Hello Proc Example");

static struct proc_dir_entry *proc_entry;

// open: called when userspace opens /proc/hello_proc
static int hello_open(struct inode *inode, struct file *file) {
    try_module_get(THIS_MODULE);  // increment refcount
    printk(KERN_INFO "hello_proc: proc file opened\n");
    return 0;
}

// release: called when userspace closes /proc/hello_proc
static int hello_release(struct inode *inode, struct file *file) {
    module_put(THIS_MODULE);      // decrement refcount
    printk(KERN_INFO "hello_proc: proc file closed\n");
    return 0;
}

// read: returns "Hello from proc\n" to userspace
static ssize_t hello_read(struct file *file, char __user *buf, size_t count, loff_t *ppos) {
    char msg[] = "Hello from proc\n";
    size_t len = sizeof(msg);

    if (*ppos >= len)
        return 0;

    if (count > len - *ppos)
        count = len - *ppos;

    if (copy_to_user(buf, msg + *ppos, count))
        return -EFAULT;

    *ppos += count;
    return count;
}

static const struct proc_ops fops = {
    .proc_open = hello_open,
    .proc_release = hello_release,
    .proc_read = hello_read,
};

// init function
static int __init hello_init(void) {
    proc_entry = proc_create(PROC_NAME, 0666, NULL, &fops);
    if (!proc_entry) {
        printk(KERN_ALERT "hello_proc: Failed to create /proc entry\n");
        return -ENOMEM;
    }
    printk(KERN_INFO "hello_proc: Module loaded\n");
    return 0;
}

// exit function
static void __exit hello_exit(void) {
    proc_remove(proc_entry);
    printk(KERN_INFO "hello_proc: Module unloaded\n");
}

module_init(hello_init);
module_exit(hello_exit);

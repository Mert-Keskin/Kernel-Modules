#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/sched.h>
#include <linux/mutex.h>

#define DEVICE_NAME "racechardev"
static int major;
static int counter = 0;   // shared global variable

static spinlock_t my_lock;
static int counter;

// Open
static int dev_open(struct inode *inode, struct file *file) {
    printk(KERN_INFO "racechardev: opened by pid=%d\n", current->pid);
    return 0;
}

// Write → increments shared counter
static ssize_t dev_write(struct file *file, const char __user *buffer,
                         size_t len, loff_t *offset) {
    int i;

    // Each byte written increments counter
    for (i = 0; i < len; i++) {
        spin_lock(&my_lock);
        counter++;
        spin_unlock(&my_lock);
    }

    printk(KERN_INFO "racechardev: counter=%d (pid=%d)\n", counter, current->pid);
    return len;
}

// Read → return current counter value
static ssize_t dev_read(struct file *file, char __user *buffer,
                        size_t len, loff_t *offset) {
    char msg[64];
    int n = snprintf(msg, sizeof(msg), "counter=%d\n", counter);

    if (*offset >= n) return 0;
    if (len > n - *offset) len = n - *offset;
    if (copy_to_user(buffer, msg + *offset, len)) return -EFAULT;

    *offset += len;
    return len;
}

// File operations
static struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = dev_open,
    .read = dev_read,
    .write = dev_write,
};

// Init
static int __init my_init(void) {
    major = register_chrdev(0, DEVICE_NAME, &fops);
    if (major < 0) {
        printk(KERN_ALERT "Failed to register char device\n");
        return major;
    }
    printk(KERN_INFO "racechardev: registered with major %d\n", major);
    /* init */
    spin_lock_init(&my_lock);
    return 0;
}

// Exit
static void __exit my_exit(void) {
    unregister_chrdev(major, DEVICE_NAME);
    printk(KERN_INFO "racechardev: unloaded\n");
}

module_init(my_init);
module_exit(my_exit);
MODULE_LICENSE("GPL");


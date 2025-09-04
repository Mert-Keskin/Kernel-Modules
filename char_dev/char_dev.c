#include <linux/module.h>
#include <linux/fs.h>          // register_chrdev
#include <linux/uaccess.h>     // copy_to_user, copy_from_user
//#include <linux/delay.h>


#define DEVICE_NAME "mychardev"
static int major;              // major number for our device
static char msg[128] = "Hello from kernel!\n";

// Open
static int dev_open(struct inode *inode, struct file *file) {
    printk(KERN_INFO "mychardev: opened\n");
    pr_debug("mychardev: opened by pid=%d\n", current->pid);
    return 0;
}

// Read
static ssize_t dev_read(struct file *file, char __user *buffer, size_t len, loff_t *offset) {
    //msleep(5000);
    int bytes = strlen(msg);
    if (*offset >= bytes) return 0;   // EOF
    if (len > bytes - *offset) len = bytes - *offset;
    if (copy_to_user(buffer, msg + *offset, len)) return -EFAULT;
    *offset += len;
    return len;
}

// Write
static ssize_t dev_write(struct file *file, const char __user *buffer, size_t len, loff_t *offset) {
    if (len > sizeof(msg) - 1) len = sizeof(msg) - 1;
    if (copy_from_user(msg, buffer, len)) return -EFAULT;
    msg[len] = '\0';
    printk(KERN_INFO "mychardev: new message: %s\n", msg);
    pr_debug("mychardev: new message: %s\n", msg);
    return len;
}

// Close
static int dev_release(struct inode *inode, struct file *file) {
    printk(KERN_INFO "mychardev: closed\n");
    pr_debug("mychardev: closed\n");
    return 0;
}

// File operations structure
static struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = dev_open,
    .read = dev_read,
    .write = dev_write,
    .release = dev_release,
};

// Init
static int __init my_init(void) {
    major = register_chrdev(0, DEVICE_NAME, &fops);
    if (major < 0) {
        printk(KERN_ALERT "Failed to register char device\n");
        return major;
    }
    printk(KERN_INFO "mychardev: registered with major %d\n", major);
    return 0;
}

// Exit
static void __exit my_exit(void) {
    unregister_chrdev(major, DEVICE_NAME);
    printk(KERN_INFO "mychardev: unloaded\n");
}

module_init(my_init);
module_exit(my_exit);
MODULE_LICENSE("GPL");

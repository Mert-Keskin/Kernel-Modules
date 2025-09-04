#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/slab.h>   // kmalloc, kfree

#define DEVICE_NAME "memchardev"
#define BUF_SIZE    1024

static int major;
static char *device_buffer;

static int dev_open(struct inode *inode, struct file *file) {
    device_buffer = kmalloc(BUF_SIZE, GFP_KERNEL);
    if (!device_buffer) {
        printk(KERN_ALERT "memchardev: kmalloc failed\n");
        return -ENOMEM;
    }
    printk(KERN_INFO "memchardev: buffer allocated\n");
    return 0;
}

static int dev_release(struct inode *inode, struct file *file) {
    if (device_buffer) {
        kfree(device_buffer);
        printk(KERN_INFO "memchardev: buffer freed\n");
    }
    return 0;
}

static ssize_t dev_write(struct file *file, const char __user *buffer,
                         size_t len, loff_t *offset) {
    if (len > BUF_SIZE) len = BUF_SIZE;
    if (copy_from_user(device_buffer, buffer, len))
        return -EFAULT;
    printk(KERN_INFO "memchardev: wrote %zu bytes\n", len);
    return len;
}

static ssize_t dev_read(struct file *file, char __user *buffer,
                        size_t len, loff_t *offset) {
    if (len > BUF_SIZE) len = BUF_SIZE;
    if (copy_to_user(buffer, device_buffer, len))
        return -EFAULT;
    printk(KERN_INFO "memchardev: read %zu bytes\n", len);
    return len;
}

static struct file_operations fops = {
    .owner   = THIS_MODULE,
    .open    = dev_open,
    .release = dev_release,
    .read    = dev_read,
    .write   = dev_write,
};

static int __init my_init(void) {
    major = register_chrdev(0, DEVICE_NAME, &fops);
    if (major < 0) {
        printk(KERN_ALERT "Failed to register char device\n");
        return major;
    }
    printk(KERN_INFO "memchardev: registered with major %d\n", major);
    return 0;
}

static void __exit my_exit(void) {
    unregister_chrdev(major, DEVICE_NAME);
    printk(KERN_INFO "memchardev: unloaded\n");
}

module_init(my_init);
module_exit(my_exit);
MODULE_LICENSE("GPL");

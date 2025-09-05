#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/slab.h>
#include <linux/vmalloc.h>
#include <linux/mm.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "mem_demo"
#define SMALL_SIZE  4096
#define LARGE_SIZE  (10 * 1024 * 1024)

static int major;
static char *kmalloc_buf;
static char *vmalloc_buf;

static char info_buf[512];   // store the output message
static size_t info_len;

// --- Read ---
static ssize_t mem_read(struct file *file, char __user *buffer,
                        size_t len, loff_t *offset)
{
    if (*offset >= info_len)
        return 0; // EOF

    if (len > info_len - *offset)
        len = info_len - *offset;

    if (copy_to_user(buffer, info_buf + *offset, len))
        return -EFAULT;

    *offset += len;
    return len;
}

static struct file_operations fops = {
    .owner = THIS_MODULE,
    .read  = mem_read,
};

static int __init mem_demo_init(void)
{
    struct page *page;
    phys_addr_t phys;

    // Register char device
    major = register_chrdev(0, DEVICE_NAME, &fops);
    if (major < 0) {
        pr_err("failed to register char device\n");
        return major;
    }

    // Allocate kmalloc buffer
    kmalloc_buf = kmalloc(SMALL_SIZE, GFP_KERNEL);
    if (kmalloc_buf) {
        page = virt_to_page(kmalloc_buf);
        phys = page_to_phys(page);
        info_len += scnprintf(info_buf + info_len, sizeof(info_buf) - info_len,
                              "kmalloc: virtual=%p, physical=%pa\n",
                              kmalloc_buf, &phys);
    } else {
        info_len += scnprintf(info_buf + info_len, sizeof(info_buf) - info_len,
                              "kmalloc failed\n");
    }

    // Try large kmalloc (may fail)
    char *big = kmalloc(LARGE_SIZE, GFP_KERNEL);
    if (!big) {
        info_len += scnprintf(info_buf + info_len, sizeof(info_buf) - info_len,
                              "kmalloc large (%d bytes) failed (expected)\n", LARGE_SIZE);
    } else {
        info_len += scnprintf(info_buf + info_len, sizeof(info_buf) - info_len,
                              "kmalloc large succeeded at %p\n", big);
        kfree(big);
    }

    // Allocate vmalloc buffer
    vmalloc_buf = vmalloc(LARGE_SIZE);
    if (vmalloc_buf) {
        info_len += scnprintf(info_buf + info_len, sizeof(info_buf) - info_len,
                              "vmalloc: virtual=%p (no simple physical)\n", vmalloc_buf);
    } else {
        info_len += scnprintf(info_buf + info_len, sizeof(info_buf) - info_len,
                              "vmalloc failed\n");
    }

    pr_info("mem_demo: loaded, major=%d\n", major);
    return 0;
}

static void __exit mem_demo_exit(void)
{
    if (kmalloc_buf)
        kfree(kmalloc_buf);
    if (vmalloc_buf)
        vfree(vmalloc_buf);

    unregister_chrdev(major, DEVICE_NAME);
    pr_info("mem_demo: unloaded\n");
}

module_init(mem_demo_init);
module_exit(mem_demo_exit);
MODULE_LICENSE("GPL");

// mmap_demo.c
#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/mm.h>
#include <linux/gfp.h>
#include <linux/slab.h>
#include <linux/uaccess.h>
#include <linux/ioctl.h>

#define DEVICE_NAME "mmap_demo"
#define MMAP_SIZE   PAGE_SIZE

/* Simple ioctl to ask kernel to print current page contents */
#define MMAP_DEMO_PRINT _IO('m', 1)

static int major;
static struct page *mpage;   /* allocated page */

/* mmap: map one page to user vma */
static int mmap_demo_mmap(struct file *file, struct vm_area_struct *vma)
{
    unsigned long pfn;
    unsigned long size = vma->vm_end - vma->vm_start;

    if (size > MMAP_SIZE)
        return -EINVAL;

    /* get PFN of the page */
    pfn = page_to_pfn(mpage);

    /* Remap physical page frame to userspace VMA */
    if (remap_pfn_range(vma, vma->vm_start, pfn, size, vma->vm_page_prot))
        return -EAGAIN;

    return 0;
}

static long mmap_demo_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
    void *kaddr;

    switch (cmd) {
    case MMAP_DEMO_PRINT:
        kaddr = page_address(mpage); /* kernel virtual address of page */
        /* ensure NUL-terminated print to avoid surprises */
        ((char *)kaddr)[MMAP_SIZE - 1] = '\0';
        pr_info("mmap_demo: page content (kernel sees): \"%s\"\n", (char *)kaddr);
        return 0;
    default:
        return -ENOTTY;
    }
}

static const struct file_operations fops = {
    .owner = THIS_MODULE,
    .mmap  = mmap_demo_mmap,
    .unlocked_ioctl = mmap_demo_ioctl,
};

static int __init mmap_demo_init(void)
{
    void *kaddr;

    major = register_chrdev(0, DEVICE_NAME, &fops);
    if (major < 0) {
        pr_err("mmap_demo: register_chrdev failed\n");
        return major;
    }

    /* allocate a single page */
    mpage = alloc_page(GFP_KERNEL);
    if (!mpage) {
        unregister_chrdev(major, DEVICE_NAME);
        pr_err("mmap_demo: alloc_page failed\n");
        return -ENOMEM;
    }

    /* place initial message */
    kaddr = page_address(mpage);
    memset(kaddr, 0, MMAP_SIZE);
    snprintf((char *)kaddr, MMAP_SIZE, "Hello from kernel mmap page!\n");

    pr_info("mmap_demo: loaded major=%d, page=%p, kernel addr=%p\n",
            major, mpage, kaddr);

    return 0;
}

static void __exit mmap_demo_exit(void)
{
    if (mpage)
        __free_page(mpage);

    unregister_chrdev(major, DEVICE_NAME);
    pr_info("mmap_demo: unloaded\n");
}

module_init(mmap_demo_init);
module_exit(mmap_demo_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("You");
MODULE_DESCRIPTION("Simple mmap demo: map one kernel page to user space");

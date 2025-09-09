#include <linux/module.h>
#include <linux/interrupt.h>
#include <linux/workqueue.h>
#include <linux/delay.h>

#define IRQ_LINE 1   // Keyboard IRQ (on x86 PCs)

static struct workqueue_struct *my_wq;
static struct work_struct my_work;

// ---------- Bottom Half (Workqueue handler) ----------
static void work_handler(struct work_struct *work)
{
    pr_info("irq_workqueue_demo: bottom half (workqueue) running on CPU %d\n",
            smp_processor_id());

    // simulate heavy work with sleep (safe here!)
    msleep(2000);

    pr_info("irq_workqueue_demo: bottom half finished heavy work\n");
}

// ---------- Top Half (IRQ handler) ----------
static irqreturn_t irq_handler(int irq, void *dev_id)
{
    pr_info("irq_workqueue_demo: top half IRQ=%d fired on CPU %d\n",
            irq, smp_processor_id());

    // queue work for bottom half
    if (my_wq)
        queue_work(my_wq, &my_work);

    return IRQ_HANDLED;
}

static int __init my_init(void)
{
    pr_info("irq_workqueue_demo: loading\n");

    // create workqueue
    my_wq = create_singlethread_workqueue("my_wq");
    if (!my_wq)
        return -ENOMEM;

    INIT_WORK(&my_work, work_handler);

    // request IRQ
    if (request_irq(IRQ_LINE, irq_handler, IRQF_SHARED,
                    "irq_workqueue_demo", &my_work)) {
        destroy_workqueue(my_wq);
        pr_err("irq_workqueue_demo: failed to request IRQ %d\n", IRQ_LINE);
        return -EIO;
    }

    pr_info("irq_workqueue_demo: loaded, listening on IRQ %d\n", IRQ_LINE);
    return 0;
}

static void __exit my_exit(void)
{
    free_irq(IRQ_LINE, &my_work);
    flush_workqueue(my_wq);
    destroy_workqueue(my_wq);
    pr_info("irq_workqueue_demo: unloaded\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");

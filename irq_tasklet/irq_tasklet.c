#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/interrupt.h>

#define KBD_IRQ 1  // Keyboard IRQ line

// Tasklet function (bottom half)
static void my_tasklet_func(struct tasklet_struct *t)
{
    pr_info("irq_tasklet_demo: bottom half running (tasklet)\n");
}

// Declare a tasklet
DECLARE_TASKLET(my_tasklet, my_tasklet_func);

// IRQ handler (top half)
static irqreturn_t irq_handler(int irq, void *dev_id)
{
    pr_info("irq_tasklet_demo: top half (IRQ handler) fired\n");

    // Schedule bottom half
    tasklet_schedule(&my_tasklet);

    return IRQ_HANDLED;
}

static int __init irq_tasklet_demo_init(void)
{
    if (request_irq(KBD_IRQ, irq_handler, IRQF_SHARED,
                    "irq_tasklet_demo", (void *)irq_handler)) {
        pr_err("irq_tasklet_demo: cannot register IRQ %d\n", KBD_IRQ);
        return -EIO;
    }
    pr_info("irq_tasklet_demo: loaded, listening on IRQ %d\n", KBD_IRQ);
    return 0;
}

static void __exit irq_tasklet_demo_exit(void)
{
    free_irq(KBD_IRQ, (void *)irq_handler);
    tasklet_kill(&my_tasklet);
    pr_info("irq_tasklet_demo: unloaded\n");
}

module_init(irq_tasklet_demo_init);
module_exit(irq_tasklet_demo_exit);

MODULE_LICENSE("GPL");

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/interrupt.h>
#include <linux/init.h>

#define KEYBOARD_IRQ 1   // on x86, keyboard is IRQ 1

// Interrupt handler
static irqreturn_t keyboard_irq_handler(int irq, void *dev_id) {
    pr_info("irq_demo: keyboard interrupt fired! irq=%d\n", irq);
    return IRQ_HANDLED; // means we handled it
}

// Init
static int __init irq_demo_init(void) {
    int ret;

    // Request the IRQ line
    ret = request_irq(KEYBOARD_IRQ,          // interrupt number
                      keyboard_irq_handler,  // handler function
                      IRQF_SHARED,           // flags (allow sharing)
                      "irq_demo",            // name (for /proc/interrupts)
                      (void *)keyboard_irq_handler); // unique dev_id
    if (ret) {
        pr_err("irq_demo: request_irq failed (%d)\n", ret);
        return ret;
    }

    pr_info("irq_demo: loaded, listening on IRQ %d\n", KEYBOARD_IRQ);
    return 0;
}

// Exit
static void __exit irq_demo_exit(void) {
    free_irq(KEYBOARD_IRQ, (void *)keyboard_irq_handler);
    pr_info("irq_demo: unloaded\n");
}

module_init(irq_demo_init);
module_exit(irq_demo_exit);

MODULE_LICENSE("GPL");

Overview

The irq_workqueue_demo kernel module demonstrates how to handle interrupts in Linux by using workqueues for the bottom half of interrupt handling. In this module, the top half handles the interrupt, and the bottom half (the potentially more time-consuming work) is deferred to a workqueue. Workqueues are useful for performing non-time-sensitive tasks without blocking the interrupt handler, allowing the kernel to handle other interrupts or tasks.

This module listens for keyboard interrupts on IRQ 1 (the standard IRQ for keyboards on x86 systems). When the interrupt occurs, the module performs the top half of interrupt handling (the IRQ handler) and then schedules the bottom half using a workqueue.

Features

Handles keyboard interrupts on IRQ 1.

Uses workqueues to defer time-consuming tasks (bottom half) from the interrupt handler.

Simulates heavy work by adding a delay (using msleep).

Logs messages for both the top half (IRQ handler) and bottom half (workqueue handler).

Provides basic logging for module loading and unloading.

Overview

The irq_demo kernel module demonstrates how to handle hardware interrupts in Linux. Specifically, this module listens for keyboard interrupts on IRQ 1 (the standard IRQ for keyboards on x86 systems). When a keyboard interrupt occurs, the module logs a message indicating that the interrupt was fired.

Features

Handles keyboard interrupts on IRQ 1.

Logs a message when the interrupt is triggered.

Allows sharing the IRQ with other devices.

Provides basic logging for loading and unloading the module.

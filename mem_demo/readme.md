Demonstrates differences between kmalloc and vmalloc in the kernel.

kmalloc: Allocates physically contiguous memory. Fast, limited by available contiguous memory.

vmalloc: Allocates virtually contiguous memory. Can allocate large buffers even if physical memory is fragmented

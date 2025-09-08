Purpose

Demonstrates how to share a kernel memory page with user-space using mmap.

Functionality

Allocates one kernel page via alloc_page().

Writes initial message in the kernel.

Exposes the page via a character device /dev/mmap_demo.

User-space program maps page with mmap().

User-space writes directly into mapped page.

Kernel can read updated page via ioctl().

Key Concepts

struct page * represents a physical page in RAM.

page_address() → kernel virtual address.

page_to_pfn() → physical page number.

remap_pfn_range() → map physical page to user-space virtual address.

Virtual addresses differ in kernel/user-space; physical page is shared.

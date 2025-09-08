#include <linux/module.h>
#include <linux/export-internal.h>
#include <linux/compiler.h>

MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};



static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd272d446, "__x86_return_thunk" },
	{ 0x0f2021e2, "remap_pfn_range" },
	{ 0x0ec278b8, "__register_chrdev" },
	{ 0xda3f53d4, "alloc_pages_noprof" },
	{ 0x52b15b3b, "__unregister_chrdev" },
	{ 0x1e2a6ab0, "__free_pages" },
	{ 0xd272d446, "__fentry__" },
	{ 0xbd03ed67, "vmemmap_base" },
	{ 0xbd03ed67, "page_offset_base" },
	{ 0xe8213e80, "_printk" },
	{ 0x7b06df01, "module_layout" },
};

static const u32 ____version_ext_crcs[]
__used __section("__version_ext_crcs") = {
	0xd272d446,
	0x0f2021e2,
	0x0ec278b8,
	0xda3f53d4,
	0x52b15b3b,
	0x1e2a6ab0,
	0xd272d446,
	0xbd03ed67,
	0xbd03ed67,
	0xe8213e80,
	0x7b06df01,
};
static const char ____version_ext_names[]
__used __section("__version_ext_names") =
	"__x86_return_thunk\0"
	"remap_pfn_range\0"
	"__register_chrdev\0"
	"alloc_pages_noprof\0"
	"__unregister_chrdev\0"
	"__free_pages\0"
	"__fentry__\0"
	"vmemmap_base\0"
	"page_offset_base\0"
	"_printk\0"
	"module_layout\0"
;

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "5A590DDDB499C18601D1710");

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
	{ 0x092a35a2, "_copy_to_user" },
	{ 0xd272d446, "__x86_return_thunk" },
	{ 0xbd03ed67, "__ref_stack_chk_guard" },
	{ 0x0ec278b8, "__register_chrdev" },
	{ 0xbd03ed67, "random_kmalloc_seed" },
	{ 0x48435057, "kmalloc_caches" },
	{ 0x81cf9e9d, "__kmalloc_cache_noprof" },
	{ 0xbd03ed67, "page_offset_base" },
	{ 0x40a621c5, "scnprintf" },
	{ 0xd710adbf, "__kmalloc_large_noprof" },
	{ 0xcb8b6ec6, "kfree" },
	{ 0xd7a59a65, "vmalloc_noprof" },
	{ 0xe8213e80, "_printk" },
	{ 0xd272d446, "__stack_chk_fail" },
	{ 0xbd03ed67, "phys_base" },
	{ 0xf1de9e85, "vfree" },
	{ 0x52b15b3b, "__unregister_chrdev" },
	{ 0xd272d446, "__fentry__" },
	{ 0x546c19d9, "validate_usercopy_range" },
	{ 0xa61fd7aa, "__check_object_size" },
	{ 0x7b06df01, "module_layout" },
};

static const u32 ____version_ext_crcs[]
__used __section("__version_ext_crcs") = {
	0x092a35a2,
	0xd272d446,
	0xbd03ed67,
	0x0ec278b8,
	0xbd03ed67,
	0x48435057,
	0x81cf9e9d,
	0xbd03ed67,
	0x40a621c5,
	0xd710adbf,
	0xcb8b6ec6,
	0xd7a59a65,
	0xe8213e80,
	0xd272d446,
	0xbd03ed67,
	0xf1de9e85,
	0x52b15b3b,
	0xd272d446,
	0x546c19d9,
	0xa61fd7aa,
	0x7b06df01,
};
static const char ____version_ext_names[]
__used __section("__version_ext_names") =
	"_copy_to_user\0"
	"__x86_return_thunk\0"
	"__ref_stack_chk_guard\0"
	"__register_chrdev\0"
	"random_kmalloc_seed\0"
	"kmalloc_caches\0"
	"__kmalloc_cache_noprof\0"
	"page_offset_base\0"
	"scnprintf\0"
	"__kmalloc_large_noprof\0"
	"kfree\0"
	"vmalloc_noprof\0"
	"_printk\0"
	"__stack_chk_fail\0"
	"phys_base\0"
	"vfree\0"
	"__unregister_chrdev\0"
	"__fentry__\0"
	"validate_usercopy_range\0"
	"__check_object_size\0"
	"module_layout\0"
;

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "3959B619ACC3907A8CB8940");

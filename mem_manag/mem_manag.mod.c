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
	{ 0x81cf9e9d, "__kmalloc_cache_noprof" },
	{ 0x546c19d9, "validate_usercopy_range" },
	{ 0xa61fd7aa, "__check_object_size" },
	{ 0x092a35a2, "_copy_from_user" },
	{ 0x0ec278b8, "__register_chrdev" },
	{ 0x52b15b3b, "__unregister_chrdev" },
	{ 0x092a35a2, "_copy_to_user" },
	{ 0xd272d446, "__fentry__" },
	{ 0xcb8b6ec6, "kfree" },
	{ 0xe8213e80, "_printk" },
	{ 0xd272d446, "__x86_return_thunk" },
	{ 0xbd03ed67, "random_kmalloc_seed" },
	{ 0x48435057, "kmalloc_caches" },
	{ 0x7b06df01, "module_layout" },
};

static const u32 ____version_ext_crcs[]
__used __section("__version_ext_crcs") = {
	0x81cf9e9d,
	0x546c19d9,
	0xa61fd7aa,
	0x092a35a2,
	0x0ec278b8,
	0x52b15b3b,
	0x092a35a2,
	0xd272d446,
	0xcb8b6ec6,
	0xe8213e80,
	0xd272d446,
	0xbd03ed67,
	0x48435057,
	0x7b06df01,
};
static const char ____version_ext_names[]
__used __section("__version_ext_names") =
	"__kmalloc_cache_noprof\0"
	"validate_usercopy_range\0"
	"__check_object_size\0"
	"_copy_from_user\0"
	"__register_chrdev\0"
	"__unregister_chrdev\0"
	"_copy_to_user\0"
	"__fentry__\0"
	"kfree\0"
	"_printk\0"
	"__x86_return_thunk\0"
	"random_kmalloc_seed\0"
	"kmalloc_caches\0"
	"module_layout\0"
;

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "6FA8D5D163F2446B048BCD8");

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
	{ 0x23f25c0a, "__dynamic_pr_debug" },
	{ 0x90a48d82, "__ubsan_handle_out_of_bounds" },
	{ 0x9479a1e8, "strnlen" },
	{ 0x092a35a2, "_copy_to_user" },
	{ 0xe54e0a6b, "__fortify_panic" },
	{ 0x0ec278b8, "__register_chrdev" },
	{ 0x52b15b3b, "__unregister_chrdev" },
	{ 0x7fb1e9ca, "const_current_task" },
	{ 0xd272d446, "__fentry__" },
	{ 0x546c19d9, "validate_usercopy_range" },
	{ 0xa61fd7aa, "__check_object_size" },
	{ 0x092a35a2, "_copy_from_user" },
	{ 0xe8213e80, "_printk" },
	{ 0xd272d446, "__x86_return_thunk" },
	{ 0x7b06df01, "module_layout" },
};

static const u32 ____version_ext_crcs[]
__used __section("__version_ext_crcs") = {
	0x23f25c0a,
	0x90a48d82,
	0x9479a1e8,
	0x092a35a2,
	0xe54e0a6b,
	0x0ec278b8,
	0x52b15b3b,
	0x7fb1e9ca,
	0xd272d446,
	0x546c19d9,
	0xa61fd7aa,
	0x092a35a2,
	0xe8213e80,
	0xd272d446,
	0x7b06df01,
};
static const char ____version_ext_names[]
__used __section("__version_ext_names") =
	"__dynamic_pr_debug\0"
	"__ubsan_handle_out_of_bounds\0"
	"strnlen\0"
	"_copy_to_user\0"
	"__fortify_panic\0"
	"__register_chrdev\0"
	"__unregister_chrdev\0"
	"const_current_task\0"
	"__fentry__\0"
	"validate_usercopy_range\0"
	"__check_object_size\0"
	"_copy_from_user\0"
	"_printk\0"
	"__x86_return_thunk\0"
	"module_layout\0"
;

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "19C70A78DA6B1AE01A0CDA5");

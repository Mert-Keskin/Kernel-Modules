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
	{ 0x6146ab8a, "module_put" },
	{ 0xbd03ed67, "__ref_stack_chk_guard" },
	{ 0x546c19d9, "validate_usercopy_range" },
	{ 0xa61fd7aa, "__check_object_size" },
	{ 0x092a35a2, "_copy_to_user" },
	{ 0xd272d446, "__stack_chk_fail" },
	{ 0xd3bd1d66, "try_module_get" },
	{ 0x0380b27c, "proc_remove" },
	{ 0xd272d446, "__fentry__" },
	{ 0x8c95c720, "proc_create" },
	{ 0xe8213e80, "_printk" },
	{ 0xd272d446, "__x86_return_thunk" },
	{ 0x7b06df01, "module_layout" },
};

static const u32 ____version_ext_crcs[]
__used __section("__version_ext_crcs") = {
	0x6146ab8a,
	0xbd03ed67,
	0x546c19d9,
	0xa61fd7aa,
	0x092a35a2,
	0xd272d446,
	0xd3bd1d66,
	0x0380b27c,
	0xd272d446,
	0x8c95c720,
	0xe8213e80,
	0xd272d446,
	0x7b06df01,
};
static const char ____version_ext_names[]
__used __section("__version_ext_names") =
	"module_put\0"
	"__ref_stack_chk_guard\0"
	"validate_usercopy_range\0"
	"__check_object_size\0"
	"_copy_to_user\0"
	"__stack_chk_fail\0"
	"try_module_get\0"
	"proc_remove\0"
	"__fentry__\0"
	"proc_create\0"
	"_printk\0"
	"__x86_return_thunk\0"
	"module_layout\0"
;

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "E038EB2329CB4BB69AA3F2C");

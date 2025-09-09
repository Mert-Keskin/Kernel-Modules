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
	{ 0x67628f51, "msleep" },
	{ 0xdf4bee3d, "alloc_workqueue" },
	{ 0x9126ce86, "request_threaded_irq" },
	{ 0xbeb1d261, "destroy_workqueue" },
	{ 0x9dd4105e, "free_irq" },
	{ 0xbeb1d261, "__flush_workqueue" },
	{ 0xd272d446, "__fentry__" },
	{ 0x7ec472ba, "cpu_number" },
	{ 0xe8213e80, "_printk" },
	{ 0x49733ad6, "queue_work_on" },
	{ 0x7b06df01, "module_layout" },
};

static const u32 ____version_ext_crcs[]
__used __section("__version_ext_crcs") = {
	0xd272d446,
	0x67628f51,
	0xdf4bee3d,
	0x9126ce86,
	0xbeb1d261,
	0x9dd4105e,
	0xbeb1d261,
	0xd272d446,
	0x7ec472ba,
	0xe8213e80,
	0x49733ad6,
	0x7b06df01,
};
static const char ____version_ext_names[]
__used __section("__version_ext_names") =
	"__x86_return_thunk\0"
	"msleep\0"
	"alloc_workqueue\0"
	"request_threaded_irq\0"
	"destroy_workqueue\0"
	"free_irq\0"
	"__flush_workqueue\0"
	"__fentry__\0"
	"cpu_number\0"
	"_printk\0"
	"queue_work_on\0"
	"module_layout\0"
;

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "EE2D793F1D1E920B887DFBF");

#include "header.h"

static void __exit remove_module(void)
{
	#ifdef DEBUG
	printk(KERNINFO "BEGIN: %s",__func__);
	#endif


	#ifdef DEBUG
	printk(KERNINFO "END: %s",__func__);
	#endif
}

module_exit(remove_module);

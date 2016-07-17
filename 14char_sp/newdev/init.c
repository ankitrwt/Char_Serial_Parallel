#include "header.h"

static int __init initialize_module(void)
{
	#ifdef DEBUG
	printk(KERNINFO "BEGIN: %s",__func__);
	#endif

	#ifdef DEBUG
	printk(KERNINFO "END: %s",__func__);
	#endif

return 0;
}

module_init(initialize_module);

#include "header.h"

static int __init func(void)
{

	printk(KERN_INFO "HELLO KERNAL\n");

return 0;
}

module_init(func);

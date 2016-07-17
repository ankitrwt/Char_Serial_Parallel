#include "header.h"

static void __exit func1(void)
{

	printk(KERN_INFO "BYE KERNAL\n");

}

module_exit(func1);

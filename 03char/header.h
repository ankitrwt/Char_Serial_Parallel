#include<linux/module.h>//printk
#include<linux/init.h>	//init_module/exit_module
#include<linux/fs.h>	//alloc_chrdev_region
#include<linux/cdev.h>	//cdev_add/cdev_del/cdev_init
#include<linux/slab.h>  //kmalloc/kfree


#ifndef DEBUG
#define DEBUG
#endif

#ifndef DEV_NAME
#define DEV_NAME "mydevice"
#endif

/*
#ifndef MAJOR
#define MAJOR
#endif
*/

#ifndef MINOR
#define MINOR 0
#endif

#ifndef NOD
#define NOD 5
#endif

#ifndef QUANTUMSIZ
#define QUANTUMSIZ 4
#endif

#ifndef QSETSIZ
#define QSETSIZ 16
#endif

#ifndef DEVICESIZ
#define DEVICESIZ 1024
#endif

#ifndef DATASIZ
#define DATASIZ 0
#endif



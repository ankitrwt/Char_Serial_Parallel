#include<linux/module.h>//printk
#include<linux/init.h>	//init_module/exit_module
#include<linux/fs.h>	//alloc_chrdev_region
#include<linux/cdev.h>	//cdev_add/cdev_del/cdev_init
#include<linux/slab.h>  //kmalloc/kfree
#include<linux/kernel.h>
#include<linux/uaccess.h> //asm-generic/uaccess.h??
#include<linux/semaphore.h>
#include<linux/ioctl.h>
#include<linux/ioport.h>
#include<linux/bitops.h>
//#include<linux/scull.h>

#ifndef DEBUG
#define DEBUG
#endif

#ifndef DEV_NAME
#define DEV_NAME "mydevice"
#endif

MODULE_LICENSE("GPL");
MODULE_AUTHOR("THIS COMP");
MODULE_DESCRIPTION("CHAR DRIVER");

/*
#ifndef MAJOR
#define MAJOR
#endif
*/

#ifndef MINOR_NO
#define MINOR_NO 0
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
#define DATASIZ 1024
#endif

#ifndef BASEADD
#define BASEADD 0x378
#endif

#ifndef DATAADD
#define DATAADD 0x378
#endif

#ifndef STATUSADD
#define STATUSADD 0x379
#endif

#ifndef CONTROLADD
#define CONTROLADD 0x37A
#endif

#ifndef MAXADDLEN
#define MAXADDLEN 3
#endif

struct scull_qset{
	void **data;
	struct scull_qset *next;
};

struct scull_dev{
	struct scull_qset *data;
	int quantum;
	int qset;
	unsigned long size;
//	unsigned int access_key;
	struct semaphore sem;
	struct cdev c_dev;
};


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
#include<asm/bitops.h>
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
//serial-----------------------------------------------------------
#ifndef BASEADD
#define BASEADD 0x0378
#endif

#ifndef RBR
#define RBR 0x0378
#endif

#ifndef THR
#define THR 0x0378
#endif

#ifndef IER
#define IER 0x0379
#endif

#ifndef IIR
#define IIR 0x037A
#endif

#ifndef FCR
#define FCR 0x037A
#endif

#ifndef LCR
#define LCR 0x037B
#endif

#ifndef MCR
#define MCR 0x037C
#endif

#ifndef LSR
#define LSR 0x037D
#endif

#ifndef MSR
#define MSR 0x037E
#endif

#ifndef SCR
#define SCR 0x037F
#endif

#ifndef DLL
#define DLL 0x0378
#endif

#ifndef DLM
#define DLM 0x0379
#endif

#ifndef MAXADDLEN
#define MAXADDLEN 8
#endif
//-----------------------------------------------------------------
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

struct serial_register {
	unsigned char rbr;
	unsigned char thr;
	unsigned char ier;
	unsigned char iir;
	unsigned char fcr;
	unsigned char lcr;
	unsigned char mcr;
	unsigned char lsr;
	unsigned char msr;
	unsigned char scr;
	unsigned char dll;
	unsigned char dlm;
};

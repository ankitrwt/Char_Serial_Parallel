#include<linux/module.h>//printk
#include<linux/init.h>	//init_module/exit_module

#ifndef DEBUG
#define DEBUG
#endif

#ifndef DERIVER_NAME
#define DERIVER_NAME "serial_port_driver"
#endif

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ANKIT");
MODULE_DESCRIPTION("SERIAL_PORT");


#ifndef MINOR_NO
#define MINOR_NO 0
#endif

#ifndef NO_OF_DEVICES
#define NO_OF_DEVICES 1
#endif

//SERIAL IO PORT ADDRESS-----------------------------------------------
#ifndef BASEADD
#define BASEADD 0x03F8
#endif

#ifndef RBR
#define RBR 0x03F8
#endif

#ifndef THR
#define THR 0x03F8
#endif

#ifndef IER
#define IER 0x03F9
#endif

#ifndef IIR
#define IIR 0x03FA
#endif

#ifndef FCR
#define FCR 0x03FA
#endif

#ifndef LCR
#define LCR 0x03FB
#endif

#ifndef MCR
#define MCR 0x03FC
#endif

#ifndef LSR
#define LSR 0x03FD
#endif

#ifndef MSR
#define MSR 0x03FE
#endif

#ifndef SCR
#define SCR 0x03FF
#endif

#ifndef DLL
#define DLL 0x03F8
#endif

#ifndef DLM
#define DLM 0x03F9
#endif

#ifndef MAXADDLEN
#define MAXADDLEN 8
#endif
//-----------------------------------------------------------------

struct scull_dev{
	struct serial_register *reg;
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

#include "header.h"
#include "var_defination.h"

/*
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
*/

void init_serial(void){
	outb(0x80,LCR);
	outb(0x03,DLL);
	outb(0x00,DLM);
	outb(0x39,LCR);
}



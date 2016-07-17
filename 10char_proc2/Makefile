INSTALL_DIR=modules
ifneq (${KERNELRELEASE},)
	obj-m := lkm.o
lkm-objs := init.o clean.o file_open.o file_close.o file_write.o file_read.o file_ioctl.o file_proc.o

else
	KERNELDIR ?= /lib/modules/$(shell uname -r)/build
	PWD := $(shell pwd)
default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
	@rm -rf ${INSTALL_DIR}
	@mkdir ${INSTALL_DIR}
	@mv -f *.o *.ko *.mod.c .*.cmd ${INSTALL_DIR}
clean:
	rm -rf ${INSTALL_DIR}
	rm modules.order
	rm Module.symvers
	rm *.o
	rm app
endif

INSTALL_DIR=modules
ifneq (${KERNELRELEASE},)
	obj-m := lkm.o
lkm-objs := init.o clean.o

else
	KERNEL_DIR ?= /lib/modules/$(shell uname -r)/build
	PWD := $(shell pwd)
default:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) modules
	@rm -rf ${INSTALL_DIR}
	@mkdir ${INSTALL_DIR}
	@mv -f *.o *.ko *.mod.c .*.cmd ${INSTALL_DIR} 
clean:
	rm -rf ${INSTALL_DIR}
	rm modules.order
	rm module.symvers
	rm *.o
	rn app
endif

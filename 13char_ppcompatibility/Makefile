INSTALL_DIR=modules
ifneq(${KERNELRELEASE},)
	obj-m := lkm.o
lkm-obj := init.o clean.o
else
	KERNEL_DIR ?= /lib/modules/$(shell uname -r)/build
	PWD := $(shell pwd)
default:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) modules
	@rm -rf ${INSTALL_DIR}
	@mkdir ${INSTALL_DIR}
	@mv *.o *.ko *.mod.c .*.cmd ${INSTALL_DIR}
clean:
	rm -rf ${INSTALL_DIR}
	rm modules.order
	rm modules.symvers
	rm *.o
	rm app
endif


UNIX:
1. What is the difference between > and >> redirection operators ?
2. How do you change File Access Permissions in UNIX OS?
3. what does command 'compgen -c' show?
4. What is the Difference between su and su- ?
5. What is difference between Hard and Soft mount?
6. Process information in the current shell can be obtained by using:
	a) kill
	b) bg
	c) fg
	d) ps
7. Any file's attribute information is stored in which structure on the disk:
	a) Inode
	b) Data blocks
	c) File blocks
	d) Directory file
8. There are two hard links to the "file1″ say hl and h2 and a softlink sl. What happens if we deleted the "file1″?
	a) We will still be able to access the file with hl and h2 but not with sl
	b) We will not be able to access the file with hl and h2 but with sl
	c) We will be able to access the file with any of hl, h2 and sl
	d) We will not be able to access the file with any of hl, h2 and sl

Programming C/C++:
1. Print numbers in the reverse order
2. Write a c++ program to accept three digits (i.e 0-9)and print all possible combinations fro these digits.(for exanple if the three digits are 1,2,3 then all possible combinations are 123,132,231,213,312,321 etc)
3. Search and Replace string
4. convert Hexa to Binary
5. Program to Convert the Content of File to UpperCase.
6. Explain features of oops 
7. Explain operator overloading with example?
8. What is diff between malloc and new?
9. What is diff between pointer and reference ?

DS: 
1. Delete from particular position
2. Add two Link List
3. Create, Display, Reverse
4. Given an unsorted linked list, and without using a temporary buffer, write a method that will delete any duplicates from the linked list?
5. Sort a linked list
 
OS:
1. What is CPU Scheduling?
2. Diff between Program and Process
3. Diff between Process and Thread
4. What is FileSystem
5. Diff between Virtual and Physical Address
6. Diff between malloc, kmalloc and vmalloc

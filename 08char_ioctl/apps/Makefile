app: main.o read.o write.o ioctl.o mainmenu.o ioctlmenu.o lseek.o
	gcc -o app main.o read.o write.o ioctl.o mainmenu.o ioctlmenu.o lseek.o

main.o: main.c decleration.h
	gcc -c main.c
read.o: read.c decleration.h
	gcc -c read.c
write.o: write.c decleration.h
	gcc -c write.c
ioctl.o: ioctl.c decleration.h
	gcc -c ioctl.c
mainmenu.o: mainmenu.c decleration.h
	gcc -c mainmenu.c
ioctlmenu.o: ioctlmenu.c decleration.h
	gcc -c ioctlmenu.c
lseek.o: lseek.c decleration.h
	gcc -c lseek.c

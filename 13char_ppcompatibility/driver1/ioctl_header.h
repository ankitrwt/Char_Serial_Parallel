#ifndef __IOCTL
#define __IOCTL

#ifndef MAGICNO
#define MAGICNO 'K'
#endif

#ifndef RESET
#define RESET _IO(MAGICNO,1)
#endif


#ifndef GETREGISTERSIZE
#define GETREGISTERSIZE _IOR(MAGICNO,2,int)
#endif


#ifndef SETREGISTERSIZE
#define SETREGISTERSIZE _IOW(MAGICNO,3,int)
#endif

#ifndef GETNOOFREGISTERS
#define GETNOOFREGISTERS _IOR(MAGICNO,4,int)
#endif

#ifndef SETNOOFREGISTERS
#define SETNOOFREGISTERS _IOW(MAGICNO,5,int)
#endif

#ifndef GETBAUDRATE
#define GETBAUDRATE _IOR(MAGICNO,6,int)
#endif

#ifndef SETBAUDRATE
#define SETBAUDRATE _IOW(MAGICNO,7,int)
#endif

#endif

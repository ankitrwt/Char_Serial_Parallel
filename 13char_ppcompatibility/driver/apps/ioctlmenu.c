#include<stdio.h>


int ioctl_menu()
{
int choice;
	printf("\nchoose from following options\n");
	printf("1. RESET\n");
	printf("2. GETREGISTERSIZE\n");
	printf("3. SETREGISTERSIZE\n");
	printf("4. GETNOOFREGISTER\n");
	printf("5. SETNOOFREGISTER\n");
	printf("6. GETBAUDRATE\n");
	printf("7. SETBAUDRATE\n");
	printf("8. EXIT\n");
	printf("\nEnter: ");
	scanf("%d",&choice);
	
return choice;
}

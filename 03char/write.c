#include<stdio.h>
#include<fcntl.h>


int main()
{
int fd;

	fd = open("./node",O_WRONLY);
	if(fd == -1)
	{
		perror("open fails\n");
		return -1;
	}
	
	close(fd);

return 0;
}

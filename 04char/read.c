#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int main()
{
int ret,fd;
char buffer[4];

	fd = open("./node",O_RDONLY);
	if(fd == -1)
	{
		perror("open fails\n");
		return -1;
	}
	
	ret = read(fd,buffer,4);
	printf("read bytes: %d\n",ret);
	printf("got string: %d\n %s\n",sizeof(buffer),buffer);
	if(ret == -1){
		perror("read() fails\n");
		return -1;
	}

	close(fd);

return 0;
}

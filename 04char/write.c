#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int main()
{
int ret,fd;
char buffer[] = "FOUR";

	fd = open("./node",O_WRONLY);
	if(fd == -1)
	{
		perror("open fails\n");
		return -1;
	}

	printf("buffer length: %d\n",strlen(buffer));
	ret = write(fd,buffer,strlen(buffer));
	printf("wrote bytes: %d\n",ret);
	if(ret == -1){
		perror("write() fails\n");
		return -1;
	}

	close(fd);

return 0;
}

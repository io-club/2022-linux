#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int fd;

	fd = open("./file1",O_RDWR);
	if (fd == -1)
	{
		printf("open failed\n");
		exit(-1);
	}
	printf("open success, fd = %d\n",fd);

	close(fd);
	return 0;
}

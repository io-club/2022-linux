#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
	int fd;
	int n_read;
	char readbuf[50] = {0};

	fd = open("./file1",O_RDWR);
	if (fd == -1)
	{
		printf("open failed\n");
		exit(-1);
	}
	printf("open success, fd = %d\n",fd);



	n_read = read(fd, readbuf, sizeof(readbuf));
	if (n_read == -1)
	{
		printf("read failed\n");
		exit(-1);
	}
	printf("read success, context:%s",readbuf);

	close(fd);
	return 0;
}

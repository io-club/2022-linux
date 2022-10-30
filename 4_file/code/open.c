#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
	int fd;

	fd = open("./file2", O_RDWR | O_CREAT, 0666);
	if (fd == -1)
	{
		printf("open failed\n");
		exit(-1);
	}
	printf("open success, fd = %d\n",fd);

	return 0;
}

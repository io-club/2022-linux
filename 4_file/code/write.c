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
	int n_write;

	char readbuf[50] = {0};
	char writebuf[12] = "ymzhenshuai";

	/* open file */
	fd = open("./file1",O_RDWR);
	if (fd == -1)
	{
		printf("open failed\n");
		exit(-1);
	}
	printf("open success, fd = %d\n",fd);

	/* write file */
	n_write = write(fd, writebuf, strlen(writebuf));
	if (n_write == -1)
	{
		printf("write failed\n");
		exit(-1);
	}
	printf("write success\n");

	/* close and open again */
	close(fd);
	fd = open("./file1", O_RDWR);
	/* read file */
	n_read = read(fd, readbuf, sizeof(readbuf));
	if (n_read == -1)
	{
		printf("read failed\n");
		exit(-1);
	}
	printf("read success, context:%s",readbuf);

	/* close file */
	close(fd);
	return 0;
}

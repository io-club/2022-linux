#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv)
{
	int fd_read;
	int fd_write;
	int n_read;
	int n_write;

	int size;

	char *readbuf = NULL;

	if(argc != 3)
	{
		printf("param error\n");
		exit(-1);
	}

	/* open file */
	fd_read = open(argv[1], O_RDWR);
	if (fd_read == -1)
	{
		printf("open read file failed\n");
		exit(-1);
	}
	printf("open success, fd = %d\n",fd_read);

	fd_write = open(argv[2], O_RDWR|O_CREAT, 0666);
	if (fd_write == -1)
	{
		printf("open write file failed\n");
		exit(-1);
	}
	printf("open success, fd = %d\n",fd_write);

	/* read file */
	size = lseek(fd_read, 0, SEEK_END);
	readbuf = (char *)malloc(sizeof(char)*size);
	lseek(fd_read, 0, SEEK_SET);
	n_read = read(fd_read, readbuf, size);
	if (n_read == -1)
	{
		printf("read failed\n");
		exit(-1);
	}
	printf("read success\n");

	/* write file */
	n_write = write(fd_write, readbuf, strlen(readbuf));
	if (n_write == -1)
	{
		printf("write failed\n");
		exit(-1);
	}
	printf("write success\n");

/*	
	if (lseek(fd, -8, SEEK_CUR) == -1)
	{
		printf("set failed\n");
		exit(-1);
	}
*/

	/* close file */
	close(fd_read);
	close(fd_write);
	return 0;
}

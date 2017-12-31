#include "apue.h"
#include <sys/types.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

int
main(void)
{
	int 		fd;
	int			ret;
	int 		a[10] = {1,2,3,4,5,6,7,8,9,10};

	int 		b;

	fd = open("outfile", O_CREAT | O_APPEND | O_RDWR, 0600);
	
	if(fd < 0)
	{
		perror("open");
		exit(1);
	}

	/*write something*/

	ret = write(fd, (void *) a, sizeof(a));

	if(ret < 0)
	{
		perror("write");
		close(fd);
		exit(1);
	}
	
	/*lseek*/

	ret = lseek(fd, 3*sizeof(int), SEEK_SET);
	
	if(ret < 0)
	{
		perror("lseek");
		close(fd);
		exit(1);
	}	
	
	/*read */

	ret = read(fd, &b, sizeof(int));

	if(ret < 0)
	{
		perror("read");
		close(fd);
		exit(1);
	}

	close(fd);

	exit(0);
}

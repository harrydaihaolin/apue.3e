#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int creat(const char *path, mode_t mode);

int
main()
{
	int i;
	i = creat("~/Documents/apue.3e/testpool/helloworld.txt", S_IRUSR);
	printf("%d\n", i);
	return 0;
}

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int
main(void)
{
	int pid;

	if ((pid = fork()) == 0)
		printf("hello from the child");
	else
		printf("hello from the parent");
	exit(0);
}

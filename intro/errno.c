#include "apue.h"
#include <errno.h>
/*none of the value from <error.h> has value 0*/
int
main(int argc, char *argv[])
{
	fprintf(stderr, "EACCES: %s\n", strerror(EACCES));	/* EACCES error*/
	errno = ENOENT;										/* set the current pid errno to ENOENT */
	perror(argv[0]);									/* "filename": "SOME ERROR MESSAGES"*/
	exit(0);
}


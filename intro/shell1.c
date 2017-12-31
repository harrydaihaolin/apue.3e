#include "apue.h"
#include <sys/wait.h>

int
main(void)
{
	char	buf[MAXLINE];	/* from apue.h */
	pid_t	pid;			/* datatype pid_t*/
	int		status;

	printf("%% ");									/* print prompt (printf requires %% to print %) */
	while (fgets(buf, MAXLINE, stdin) != NULL) {	/* read one line at a time from standard input */
		if (buf[strlen(buf) - 1] == '\n')			
			buf[strlen(buf) - 1] = 0; 				/* replace newline with null */

		if ((pid = fork()) < 0) {					/* fork returns a new child process to the parent processID and return 0 to the child*/
			err_sys("fork error");			
		} else if (pid == 0) {						/* child */
			execlp(buf, buf, (char *)0);			/* execute command from the stdin */
			err_ret("couldn't execute: %s", buf);	/* */
			exit(127);
		}

		/* The parent wants to wait for the child to terminate and then get ready to execute a new one */								
		if ((pid = waitpid(pid, &status, 0)) < 0) 	/* waitpid(pid, the status variable, termination status) it returns*/
			err_sys("waitpid error");
		printf("%% ");
	}
	exit(0);
}

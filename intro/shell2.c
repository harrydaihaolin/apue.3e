#include "apue.h"
#include <sys/wait.h>

/***************
* signal are a techinique used to notify a process that some condition has occured.
* ex. SIGFPE(floating point exception) is sent a process like divides by zero
* This program is called the barebone shell because 
****************/
static void	sig_int(int);							/* our signal-catching function */

int
main(void)
{
	char	buf[MAXLINE];							/* from apue.h */
	pid_t	pid;
	int		status;

	if (signal(SIGINT, sig_int) == SIG_ERR)			/* SIGINT signal is used to terminate the current process*/
		err_sys("signal error");

	printf("%% ");									/* print prompt (printf requires %% to print %) */
	while (fgets(buf, MAXLINE, stdin) != NULL) 		/* fgets(BUFFER STRING, MAXSIZE OF STRING, STANDARD INPUT) returns file pointer*/
	{
		if (buf[strlen(buf) - 1] == '\n')
			buf[strlen(buf) - 1] = 0; 				/* replace newline with null */

		/* child */
		if ((pid = fork()) < 0) 					/* return the new process ID and return 0 to the child*/
		{
			err_sys("fork error");
		} 
		else if (pid == 0) 							
		{						
			execlp(buf, buf, (char *)0);			
			err_ret("couldn't execute: %s", buf);
			exit(127);								/* the current process ID is supposed to terminate with a 127 error*/
		}

		/* parent */
		if ((pid = waitpid(pid, &status, 0)) < 0)	/* waitpid return the specified parent process to terminate */
			err_sys("waitpid error");
		printf("%% ");
	}
	exit(0);
}

void
sig_int(int signo)
{
	printf("interrupt\n%% ");						/* it prints a message and a new prompt*/
}

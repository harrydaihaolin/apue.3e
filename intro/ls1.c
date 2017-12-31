#include "apue.h"
#include <dirent.h>

int
main(int argc, char *argv[])
{
	DIR				*dp;						/*pointer to DIR structure*/
	struct dirent	*dirp;						/*pointer to direct structure*/

	if (argc != 2)
		err_quit("usage: ls directory_name");

	if ((dp = opendir(argv[1])) == NULL)		/*system error if this directory cannot be opened*/
		err_sys("can't open %s", argv[1]);
	while ((dirp = readdir(dp)) != NULL)		/*what readdir(dp) returns is d_name*/
		printf("%s\n", dirp->d_name);

	closedir(dp);								/*close the directory everytime after using it.*/
	exit(0);
}

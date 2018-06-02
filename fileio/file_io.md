# FILE I/O

-	File Descriptors
	-	All files are referred to by Fd
	-	open or creat or read or write
	-	0 -- std input, 1 -- std output
		-	constants in <unistd.h> header
	-	`OFLAG`
		-	from <fcntl.h> header
		-	O_RDONLY, O_WRONLY, O_RDWR ...
```c
#include <fcntl.h>

int open(const char *path, int oflag, ... /* mode_t mode */);

int openat(int fd, const char *path, int oflag, ... /* mode_t mode */);

```

##	creat function
```c

#include <fcntl.h>

int creat(const char *path, mode_t mode);

/* provide read and write access and creation of file and if file is opened file size truncated to 0*/
/* equivalent to*/

int open (path, O_RDWR | O_CREAT | O_TRUNC, mode);
```
## close function 
```c

#include <unistd.h>

int close(int fd);
```



#include "get_next_line.h"


int	main(void)
{
	//	Open a file descriptor for the "test.txt" file, in
    //	truncated write only mode, and create the file if it doesn't
    //	already exist. Read and write permissions for the owner, read
    // //	permissions for the group.
    int fd = open("file.txt", O_RDONLY);
    int i = 0;
    // //	Stop everything if the file could not be opened
	if (fd == -1)
		return (1);
	printf("fd = %d\n", fd);
    while(i < 6)
    {
	    printf("%d:\n%s\n",i, get_next_line(fd));
        i++;
    }

	close(fd);
	return 0;
}
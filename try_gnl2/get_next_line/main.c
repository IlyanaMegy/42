#include "get_next_line.h"
// https://git.chevro.fr/42-cestoliv/get_next_line/-/blob/main/get_next_line.c
// https://github.com/n1kito/Get_next_line/blob/main/src/get_next_line.c

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
    char *line;
	printf("fd = %d\n", fd);
    while(fd != -1)
    {
	    line = get_next_line(fd);
        if (!line)
            break;
        printf("%d:\ns%\n", i++, line);
        free(line);
    }
	close(fd);
	return 0;
}
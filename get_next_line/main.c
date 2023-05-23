#include "get_next_line.h"

int	main(void)
{
	int fd;
	char *line;
	int i = 0;

	fd = open("file.txt", O_RDONLY);
	// printf("%d\n%s\n", 1, get_next_line(fd));
    // printf("%d\n%s\n", 2, get_next_line(fd));
	while (1)
	{
		line = get_next_line(fd);
		printf("%d\n%s\n", i++, line);
		if (line == NULL)
			break ;
		free(line);
	}
	close(fd);
	return (0);
}
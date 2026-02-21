/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltorkia <ltorkia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 22:19:44 by ltorkia           #+#    #+#             */
/*   Updated: 2024/04/29 02:14:52 by ltorkia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*extract_line(char *line)
{
	size_t	count;
	char	*next_line;

	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	if (line[count] == '\0' || line[count + 1] == '\0')
		return (0);
	next_line = ft_substr(line, count + 1, ft_strlen(line) - count - 1);
	if (!next_line)
		next_line = 0;
	line[count + 1] = '\0';
	return (next_line);
}

static char	*read_and_save(int fd, char *buffer, char *save)
{
	int		read_bytes;
	char	*temp_save;

	read_bytes = 1;
	while (read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (0);
		if (read_bytes == 0)
			break ;
		buffer[read_bytes] = '\0';
		if (!save)
			save = ft_strdup("");
		temp_save = save;
		save = ft_strjoin(temp_save, buffer);
		free(temp_save);
		temp_save = 0;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (save);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*save_next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	line = read_and_save(fd, buffer, save_next_line);
	free(buffer);
	if (!line)
	{
		free(line);
		return (0);
	}
	save_next_line = extract_line(line);
	return (line);
}

// #include <stdio.h>
// #include <sys/stat.h>
// #include <fcntl.h>

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("fd1.txt", O_RDONLY);
// 	if (fd < 3)
// 		return (-1);
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		printf("%s\n", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	close(fd);
// 	return (0);
// }

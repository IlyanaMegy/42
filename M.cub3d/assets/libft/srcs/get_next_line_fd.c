/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltorkia <ltorkia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 22:19:44 by ltorkia           #+#    #+#             */
/*   Updated: 2023/06/20 16:55:48 by ltorkia          ###   ########.fr       */
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
	{
		free(next_line);
		next_line = 0;
	}
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

char	*get_next_line_fd(int fd)
{
	char		*buffer;
	char		*line;
	static char	*save_next_line[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	line = read_and_save(fd, buffer, save_next_line[fd]);
	free(buffer);
	if (!line)
	{
		free(line);
		return (0);
	}
	save_next_line[fd] = extract_line(line);
	return (line);
}

// #include <stdio.h>
// #include <sys/stat.h>
// #include <fcntl.h>

// int	main(void)
// {
// 	int		fd1, fd2;
// 	char	*line;

// 	fd1 = open("fd1.txt", O_RDONLY);
// 	fd2 = open("fd2.txt", O_RDONLY);

// 	// APPEL 1 : PREMIER FICHIER
// 	line = get_next_line(fd1);
// 	printf("Fichier 1 / APPEL 1 : %s\n", line);
// 	free(line);

// 	// APPEL 1 : DEUXIEME FICHIER
// 	line = get_next_line(fd2);
// 	printf("Fichier 2 / APPEL 1 : %s\n", line);
// 	free(line);

// 	// APPEL 2 : PREMIER FICHIER
// 	line = get_next_line(fd1);
// 	printf("Fichier 1 / APPEL 2 : %s\n", line);
// 	free(line);
// 	line = get_next_line(fd1);
// 	close(fd1);

// 	// APPEL 2 : DEUXIEME FICHIER
// 	line = get_next_line(fd2);
// 	printf("Fichier 2 / APPEL 2 : %s\n", line);
// 	free(line);

// 	close(fd1);
// 	close(fd2);

// 	return (0);
// }

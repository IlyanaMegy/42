/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:58:52 by ilymegy           #+#    #+#             */
/*   Updated: 2023/05/17 10:58:55 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

// char	*empty_str(void)
// {
// 	char	*str;

// 	str = (char *)malloc(sizeof(char));
// 	if (!str)
// 		return (NULL);
// 	str[0] = 0;
// 	return (str);
// }

// void	shiftstr(char **str, size_t start)
// {
// 	char	*tmp;

// 	tmp = *str;
// 	*str = ft_substr(*str, start, ft_strlen(*str));
// 	free(tmp);
// }

// int	get_prev(char **previous, int fd)
// {
// 	char	*str;
// 	ssize_t	res;

// 	if (!BUFFER_SIZE || BUFFER_SIZE < 1 || fd < 0 || read(fd, 0, 0) < 0)
// 		return (0);
// 	if (!(*previous))
// 		*previous = empty_str();
// 	if (!(*previous))
// 		return (0);
// 	str = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
// 	if (!str)
// 		return (0);
// 	res = read(fd, str, BUFFER_SIZE);
// 	while (res)
// 	{
// 		str[res] = 0;
// 		*previous = ft_strjoin(*previous, str);
// 		if (ft_strchr(*previous, '\n') >= 0)
// 			break ;
// 		res = read(fd, str, BUFFER_SIZE);
// 	}
// 	free(str);
// 	return (1);
// }

// char	*get_next_line(int fd)
// {
// 	static char	*prev;
// 	char		*readed;
// 	int			i;

// 	prev = NULL;
// 	if (!get_prev(&prev, fd))
// 		return (NULL);
// 	i = ft_strchr(prev, '\n');
// 	if (i >= 0)
// 	{
// 		readed = ft_substr(prev, 0, i + 1);
// 		shiftstr(&prev, i + 1);
// 	}
// 	else
// 	{
// 		readed = ft_substr(prev, 0, ft_strlen(prev));
// 		free(prev);
// 		prev = NULL;
// 	}
// 	if (ft_strlen(readed) == 0)
// 	{
// 		free(readed);
// 		return (NULL);
// 	}
// 	return (readed);
// }

char	*get_next_line(int fd)
{
	int		i;
	int		rd;
	char	character;
	char	*buffer;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	i = 0;
	rd = read(fd, &character, BUFFER_SIZE - BUFFER_SIZE + 1);
	printf("rd = %d\n", rd);
	buffer = malloc(100000);
	if (rd > 0)
	{
		while (rd > 0)
		{
			buffer[i++] = character;
			if (character == '\n')
				break ;
			rd = read(fd, &character, BUFFER_SIZE - BUFFER_SIZE + 1);
		}
	}
	buffer[i] = '\0';
	if (rd == -1 || i == 0 || (!buffer[i - 1] && !rd))
		return (free(buffer), NULL);
	return (buffer);
}

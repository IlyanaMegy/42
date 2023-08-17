/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <ilyanamegy@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:58:52 by ilymegy           #+#    #+#             */
/*   Updated: 2023/07/21 15:50:09 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	clean_me(t_gnl **str)
{
	t_gnl	*last;
	t_gnl	*clear;
	int		i;
	int		j;

	clear = malloc(sizeof(t_gnl));
	if (!clear || !str)
		return ;
	clear->next = NULL;
	last = get_last(*str);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content && last->content[i] == '\n')
		i++;
	clear->content = malloc(sizeof(char) * ((ft_len(last->content) - i) + 1));
	if (!(clear->content))
		return ;
	j = 0;
	while (last->content[i])
		clear->content[j++] = last->content[i++];
	clear->content[j] = '\0';
	free_str(*str);
	*str = clear;
}

void	extract_me(t_gnl *str, char **line)
{
	int	i;
	int	j;

	if (!str)
		return ;
	create_line(str, line);
	if (!(*line))
		return ;
	j = 0;
	while (str)
	{
		i = 0;
		while (str->content[i])
		{
			if (str->content[i] == '\n')
			{
				(*line)[j++] = str->content[i];
				break ;
			}
			(*line)[j++] = str->content[i++];
		}
		str = str->next;
	}
	(*line)[j] = '\0';
}

void	add_to_str(t_gnl **str, char *buffer, int size)
{
	int		i;
	t_gnl	*last;
	t_gnl	*new;

	new = malloc(sizeof(t_gnl));
	if (!new)
		return ;
	new->next = NULL;
	new->content = malloc(sizeof(char) * (size + 1));
	if (!(new->content))
		return ;
	i = 0;
	while (buffer[i] && i < size)
	{
		new->content[i] = buffer[i];
		i++;
	}
	new->content[i] = '\0';
	if (!(*str))
	{
		*str = new;
		return ;
	}
	last = get_last(*str);
	last->next = new;
}

void	read_me(int fd, t_gnl **str)
{
	char	*buffer;
	int		size_readed;

	size_readed = 1;
	while (!is_newline(*str) && size_readed != 0)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		size_readed = (int)read(fd, buffer, BUFFER_SIZE);
		if ((size_readed == 0 && !(*str)) || size_readed == -1)
		{
			free(buffer);
			return ;
		}
		buffer[size_readed] = '\0';
		add_to_str(str, buffer, size_readed);
		free(buffer);
	}
}

char	*get_next_line(int fd)
{
	static t_gnl	*str = NULL;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	read_me(fd, &str);
	if (!str)
		return (NULL);
	extract_me(str, &line);
	clean_me(&str);
	if (line[0] == '\0')
	{
		free_str(str);
		str = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

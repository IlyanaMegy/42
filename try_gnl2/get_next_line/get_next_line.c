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

/* clean str to keep just the char needed*/
void	clean_me(t_list **str)
{
	t_list	*last;
	t_list	*cleaned;
	int		i;
	int		j;
	int		len;

	cleaned = malloc(sizeof(t_list));
	if (!cleaned)
		return ;
	cleaned->next = NULL;
	last = get_last(*str);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content[i] && last->content[i] == '\n')
		i++;
	len = ft_strlen(last->content) - i;
	cleaned->content = malloc(sizeof(char) * (len + 1));
	if (!cleaned->content)
		return ;
	j = 0;
	while (last->content[i])
		cleaned->content[j++] = last->content[i++];
	cleaned->content[j] = '\0';
	free_str(*str);
	*str = cleaned;
}

/* extract char from str and add to line until \n included*/
void	extract_me(t_list *str, char **line)
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

void	add_to_str(t_list **str, char *buffer, int size)
{
	int		i;
	t_list	*last;
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	new->next = NULL;
	new->content = malloc(sizeof(char) * (size + 1));
	if (!new->content)
		return ;
	i = 0;
	while (buffer[i] && i < size)
	{
		new->content[i] = buffer[i];
		i++;
	}
	new->content[i] = '\0';
	if (!str) // if str is empty (1st try)
	{
		*str = new;
		return ;
	}
	last = get_last(*str);
	last->next = new;
}

void	read_me(int fd, t_list **str)
{
	char	*buffer;
	int		size_readed;

	size_readed = 1;
	while (!is_newline(*str) && size_readed != 0)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return ;
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
	static t_list	*str;
	char			*line;

	str = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	line = NULL;
	// read from fd and add to str
	read_me(fd, &str);
	if (!str) // empty file
		return (NULL);
	// extract from str and add to line
	extract_me(str, &line);
	// clean str
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

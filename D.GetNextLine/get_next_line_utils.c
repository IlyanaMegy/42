/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:59:13 by ilymegy           #+#    #+#             */
/*   Updated: 2023/05/17 10:59:17 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_len(const char *str)
{
	int	n;

	n = 0;
	while (str[n])
		++n;
	return (n);
}

int	is_newline(t_list *s)
{
	int		i;
	t_list	*curr;

	i = 0;
	if (!s)
		return (0);
	curr = get_last(s);
	while (curr->content[i])
	{
		if (curr->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_list	*get_last(t_list *str)
{
	t_list	*s;

	s = str;
	while (s && s->next)
		s = s->next;
	return (s);
}

void	create_line(t_list *str, char **line)
{
	int	i;
	int	len;

	len = 0;
	while (str)
	{
		i = 0;
		while (str->content[i])
		{
			if (str->content[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		str = str->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
}

void	free_str(t_list *str)
{
	t_list	*s;
	t_list	*tmp;

	s = str;
	while (s)
	{
		free(s->content);
		tmp = s->next;
		free(s);
		s = tmp;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeaude <pabeaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:24:55 by pabeaude          #+#    #+#             */
/*   Updated: 2023/09/21 12:40:30 by pabeaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_free(char *str)
{
	free(str);
	return (NULL);
}

/* supprime les char apres le '\n'*/
char	*ft_remove(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (!stash || !stash[0])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	line [i] = '\0';
	while (--i >= 0)
		line [i] = stash [i];
	return (line);
}

/* ajoute ce qui a etait supprimer dans
remove pour la prochaine ligne */
char	*ft_add(char *stash)
{
	char	*newstash;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\0')
	{
		free(stash);
		return (NULL);
	}
	newstash = malloc(sizeof(char) * (gnl_strlen(stash) - i + 1));
	if (!newstash)
		return (NULL);
	while (stash[i])
		newstash[j++] = stash[++i];
	newstash[j++] = '\0';
	free(stash);
	return (newstash);
}

/*Li les n premier char jusqu'a un '\n'
ou un '\0' et me la renvoie dans save ()*/
char	*read_line(int fd, char *save)
{
	char	*buffer;
	int		red;

	red = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (red > 0)
	{
		red = read(fd, buffer, BUFFER_SIZE);
		if (red == -1)
			return (ft_free(buffer));
		buffer[red] = '\0';
		save = gnl_strjoin(save, buffer);
		if (!save)
		{
			free(buffer);
			return (ft_free(save));
		}
		if (gnl_strrchr(save, '\n'))
			break ;
	}
	free (buffer);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	stash[fd] = read_line(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = ft_remove(stash[fd]);
	stash[fd] = ft_add(stash[fd]);
	return (line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <ilyanamegy@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:33:19 by ilymegy           #+#    #+#             */
/*   Updated: 2023/08/16 23:13:11 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	join_me(char **lines, char **curr)
{
	char	*tmp;

	tmp = *lines;
	*lines = ft_strjoin(*lines, *curr);
	free(tmp);
	free(*curr);
}

void	pass_empty_lines(char **lines, int *fd)
{
	*lines = get_next_line(*fd);
	while (*lines && *lines[0] == '\n')
	{
		free(*lines);
		*lines = get_next_line(*fd);
	}
}

char	**get_map(char *map_file, t_game *game)
{
	char	*curr;
	char	*lines;
	int		fd;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		end_game("Error while trying opening the map.", game, file_error, NULL);
	pass_empty_lines(&lines, &fd);
	if (lines[0] == '\0')
	{
		close(fd);
		end_game("This file is empty!", game, file_error, lines);
	}
	curr = get_next_line(fd);
	while (curr)
	{
		if (curr[0] == '\n')
		{
			free(curr);
			break ;
		}
		join_me(&lines, &curr);
		curr = get_next_line(fd);
	}
	close(fd);	
	return (ft_split(lines, '\n'));
}

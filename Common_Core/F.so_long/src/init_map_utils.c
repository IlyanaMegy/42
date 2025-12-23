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

void	join_me(char **lines, char **curr, t_game *game)
{
	char	*tmp;

	tmp = *lines;
	*lines = ft_strjoin(*lines, *curr);
	free(tmp);
	free(*curr);
	if (!(*lines))
		end_game("Error trying saving the map.", game, file_error, NULL);
}

void	pass_empty_lines(char **lines, int *fd, t_game *game, int *err)
{
	*lines = get_next_line(*fd, err);
	if (!(*lines))
		end_game("This file is empty!", game, file_error, NULL);
	while (*lines && *lines[0] == '\n')
	{
		free(*lines);
		*lines = get_next_line(*fd, err);
	}
	return ;
}

char	**get_map(char *map_file, t_game *game, int err)
{
	char	*curr;
	char	*lines;
	int		fd;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		end_game("Error trying opening the map.", game, file_error, NULL);
	pass_empty_lines(&lines, &fd, game, &err);
	curr = get_next_line(fd, &err);
	if (!curr)
		free(lines);
	while (curr)
	{
		if (curr[0] == '\n')
		{
			free(curr);
			break ;
		}
		join_me(&lines, &curr, game);
		curr = get_next_line(fd, &err);
		if (err == 1)
			end_game("Error trying saving the map.", game, file_error, NULL);
	}
	return (ft_split(lines, '\n'));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:40:24 by ilymegy           #+#    #+#             */
/*   Updated: 2023/07/28 16:40:29 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	get_height(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}

int	check_line(char *line)
{
	int	i;

	i = 0;
	while (line && line[i] != '\0')
	{
		if (line[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

void	check_map_valid(t_game *game, char *map_file, int err)
{
	t_game_map	map;

	map.p = 0;
	map.e = 0;
	map.b = 0;
	map.y = game->map_size.y - 1;
	check_map_rect(game);
	check_map_walls(game);
	check_map_elem(game, &map);
	is_map_playable(game, map_file, err);
}

int	to_find(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

int	is_out(int x, int y, int size_x, int size_y)
{
	return (y < 0 || y >= size_y || x < 0 || x >= size_x);
}

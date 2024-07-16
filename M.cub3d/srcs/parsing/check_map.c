/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltorkia <ltorkia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:14:27 by ltorkia           #+#    #+#             */
/*   Updated: 2024/07/02 16:09:31 by ltorkia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

/// @brief check if player count, direction and walls around are valid
/// @param data: data to check
/// @param map: map to check
/// @return true if valid, false otherwise
static bool	check_player(t_data *data, char **map)
{
	int		i;
	int		j;

	i = -1;
	data->player.dir = '\0';
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (ft_strchr("NSWE", map[i][j]) && !data->player.dir)
			{
				data->player.dir = map[i][j];
				map[i][j] = '0';
				data->player.pos_x = (double)j + 0.5;
				data->player.pos_y = (double)i + 0.5;
			}
			else if (ft_strchr("NSWE", map[i][j]) && data->player.dir)
				return (error_msg(ERR_NUM_PLAYER, NULL), false);
		}
	}
	if (!data->player.dir)
		return (error_msg(ERR_PLAYER_DIR, NULL), false);
	return (true);
}

/// @brief check if there is a wall (1) to close the map
///			around the player and each 0
/// @param map: map
/// @param i: n line
/// @param j: n char
/// @param f: function to check the side
/// @return true if the map is closed, false otherwise
static bool	check_sides(char **map, int i, int j,
	int (*f)(char **, int, int))
{
	char	c;

	c = f(map, i, j);
	if (c != -1 && ft_strchr("NSWE0 ", c))
		return (false);
	return (true);
}

/// @brief check if there is a wall (1) to close the map
///			around the player and each 0
/// @param map: map
/// @return true if valid, false otherwise
static bool	is_closed(char **map)
{
	int		i;
	int		j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (ft_strchr("0NSWE", map[i][j])
				&& (!check_sides(map, i, j, &to_top)
					|| !check_sides(map, i, j, &to_right)
					|| !check_sides(map, i, j, &to_left)
					|| !check_sides(map, i, j, &to_bottom)))
				return (error_msg(ERR_MAP_NO_WALLS, NULL), false);
		}
	}
	spaces_into_walls(map);
	return (true);
}

/// @brief check if texture file is valid
/// @param data: data to check
/// @return true if valid, false otherwise
static bool	check_infos(t_data *data)
{
	if (!file_is_valid(data->txt.north_path, ".xpm")
		|| !file_is_valid(data->txt.south_path, ".xpm")
		|| !file_is_valid(data->txt.west_path, ".xpm")
		|| !file_is_valid(data->txt.east_path, ".xpm"))
		return (false);
	return (true);
}

/// @brief check if the map is valid
///			--check texture files are valid (path + extension .xpm)
///			--check if the map is empty
///			--check if there is a wall (1) to close
///				the map around player + each 0
///				if so, replace spaces by walls to make the map square
///			--check player count and direction are valid
/// @param data: data to check
/// @param map: map to check
/// @return true if valid, false otherwise
bool	map_is_valid(t_data *data, char **map)
{
	if (!check_infos(data))
		return (false);
	if (!map || !map[0])
		return (error_msg(ERR_EMPTY_MAP, NULL), false);
	if (!is_closed(map))
		return (false);
	if (!check_player(data, map))
		return (false);
	return (true);
}

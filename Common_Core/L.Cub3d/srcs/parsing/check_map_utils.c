/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltorkia <ltorkia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:28:20 by ltorkia           #+#    #+#             */
/*   Updated: 2024/07/04 17:51:26 by ltorkia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

/// @brief check if player or 0 is closed by a wall (1) on the top
/// @param map: map
/// @param i: n line
/// @param j: n char
/// @return -1 if the map is closed, the wrong char if not
int	to_top(char **map, int i, int j)
{
	while (map && i >= 0 && ft_strchr("0NSWE", map[i][j]))
		i--;
	if (map && i >= 0 && map[i][j] != '1')
		return (map[i][j]);
	else if (map && i == -1 && map[0][j] && map[0][j] != '1')
		return (map[0][j]);
	return (-1);
}

/// @brief check if player or 0 is closed by a wall (1) on the bottom
/// @param map: map
/// @param i: n line
/// @param j: n char
/// @return -1 if the map is closed, the wrong char if not
int	to_bottom(char **map, int i, int j)
{
	while (map && map[i] && map[i][j] && ft_strchr("0NSWE", map[i][j]))
		i++;
	if (map && map[i] && map[i][j] && map[i][j] != '1')
		return (map[i][j]);
	else if (map && !map[i] && map[i - 1][j] && map[i - 1][j] != '1')
		return (map[i - 1][j]);
	return (-1);
}

/// @brief check if player or 0 is closed by a wall (1) on the left
/// @param map: map
/// @param i: n line
/// @param j: n char
/// @return -1 if the map is closed, the wrong char if not
int	to_left(char **map, int i, int j)
{
	while (map && map[i] && j >= 0 && ft_strchr("0NSWE", map[i][j]))
		j--;
	if (map && map[i] && j >= 0 && map[i][j] != '1')
		return (map[i][j]);
	else if (map && map[i] && j == -1 && map[i][0] && map[i][0] != '1')
		return (map[i][0]);
	return (-1);
}

/// @brief check if player or 0 is closed by a wall (1) on the right
/// @param map: map
/// @param i: n line
/// @param j: n char
/// @return -1 if the map is closed, the wrong char if not
int	to_right(char **map, int i, int j)
{
	while (map && map[i] && map[i][j] && ft_strchr("0NSWE", map[i][j]))
		j++;
	if (map && map[i] && map[i][j] && map[i][j] != '1')
		return (map[i][j]);
	else if (map && map[i] && !map[i][j]
		&& map[i][j - 1] && map[i][j - 1] != '1')
		return (map[i][j - 1]);
	return (-1);
}

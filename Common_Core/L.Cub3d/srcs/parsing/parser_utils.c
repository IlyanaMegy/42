/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltorkia <ltorkia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:23:47 by ltorkia           #+#    #+#             */
/*   Updated: 2024/05/17 17:13:28 by ltorkia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

/// @brief replace spaces by walls (1) to end with only valid chars
/// @param map: map
void	spaces_into_walls(char **map)
{
	int		i;
	int		j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (ft_isspace(map[i][j]))
				map[i][j] = '1';
		}
	}
}

/// @brief check if the line is empty (with one or more spaces)
/// @param line: line
/// @return: true if empty, false otherwise
bool	line_is_empty(char *line)
{
	int			space_count;
	int			i;

	space_count = 0;
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (ft_isspace(line[i]))
			space_count++;
		else
			space_count--;
		i++;
	}
	if (space_count != i)
		return (false);
	return (true);
}

/// @brief if empty lines found during txt/rgb parsing and before map,
///			skip them by increasing row index
/// @param data: data
/// @param row: row index
bool	check_empty_lines(t_data *data, int (*row), bool map_check)
{
	while (data->map.file[(*row)]
		&& ft_strncmp(data->map.file[(*row)], "\n", 1) == 0)
		(*row)++;
	if (!data->map.file[(*row)])
	{
		if (map_check)
			return (error_msg(ERR_INVALID_MAP, NULL), false);
		else
			return (error_msg(ERR_EMPTY_FILE, NULL), false);
	}
	return (true);
}

/// @brief check if a texture / rgb is doubled before map parsing
/// @param data: data
/// @param file: file
/// @param row: row index
/// @return true if success, false otherwise
bool	check_double_txt(t_data *data, char **file, int (*row))
{
	int	i;

	i = 0;
	if (data->txt.north_path && data->txt.south_path && data->txt.west_path
		&& data->txt.east_path && data->txt.floor_rgb && data->txt.ceil_rgb)
	{
		(*row)++;
		while (file[(*row)][i] && ft_isspace(file[(*row)][i]))
			i++;
		if (!ft_strncmp(&file[(*row)][i], "NO", 2)
			|| !ft_strncmp(&file[(*row)][i], "SO", 2)
			|| !ft_strncmp(&file[(*row)][i], "WE", 2)
			|| !ft_strncmp(&file[(*row)][i], "EA", 2)
			|| !ft_strncmp(&file[(*row)][i], "F", 1)
			|| !ft_strncmp(&file[(*row)][i], "C", 1))
			return (error_msg(ERR_TEX_COLOR_DOUBLE, NULL), false);
	}
	return (true);
}

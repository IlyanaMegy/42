/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_infos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltorkia <ltorkia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:23:47 by ltorkia           #+#    #+#             */
/*   Updated: 2024/05/16 17:45:28 by ltorkia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

/// @brief check if the line is valid or if a texture / rgb is doubled
/// @param data: data
/// @param line: line
/// @param i: index
/// @return true if success, false otherwise
static bool	check_random_line(t_data *data, char *line, int i)
{
	if ((data->txt.north_path && !ft_strncmp(&line[i], "NO", 2))
		|| (data->txt.south_path && !ft_strncmp(&line[i], "SO", 2))
		|| (data->txt.west_path && !ft_strncmp(&line[i], "WE", 2))
		|| (data->txt.east_path && !ft_strncmp(&line[i], "EA", 2))
		|| (data->txt.floor_rgb && !ft_strncmp(&line[i], "F", 1))
		|| (data->txt.ceil_rgb && !ft_strncmp(&line[i], "C", 1)))
		return (error_msg(ERR_TEX_COLOR_DOUBLE, NULL), false);
	else if (line_is_empty(line)
		|| (ft_strncmp(&line[i], "NO", 2) && ft_strncmp(&line[i], "SO", 2)
			&& ft_strncmp(&line[i], "WE", 2) && ft_strncmp(&line[i], "EA", 2)
			&& ft_strncmp(&line[i], "F", 1) && ft_strncmp(&line[i], "C", 1)
			&& line[i] && !ft_strchr("10NSWE\n", line[i])))
		return (error_msg(ERR_INVALID_LINE, NULL), false);
	return (true);
}

/// @brief check, at the end of the file, if one texture / rgb is missing
///			or if the map is empty or misplaced (not at the end of the file)
/// @param line
/// @param i
/// @return
static bool	check_txt_missing(char *line, int i)
{
	if (!ft_strncmp(&line[i], "NO", 2) || !ft_strncmp(&line[i], "SO", 2)
		|| !ft_strncmp(&line[i], "WE", 2) || !ft_strncmp(&line[i], "EA", 2)
		|| !ft_strncmp(&line[i], "F", 1) || !ft_strncmp(&line[i], "C", 1))
		return (error_msg(ERR_INVALID_MAP, NULL), false);
	else
		return (error_msg(ERR_TEX_COLOR_MISSING, NULL), false);
	return (true);
}

/// @brief save txt path or rgb data depending on parameters
/// @param ptr: pointer to save
/// @param dir: direction given
/// @param line: line to compare
/// @param i: index
/// @return true if success, false otherwise
static bool	get_info(void **ptr, char *dir, char *line, int *i)
{
	int		**int_ptr;
	char	**char_ptr;

	int_ptr = (int **)ptr;
	char_ptr = (char **)ptr;
	if (!(*char_ptr) && !ft_strncmp(&line[(*i)], dir, 2)
		&& (!ft_strncmp(dir, "NO", 2) || !ft_strncmp(dir, "SO", 2)
			|| !ft_strncmp(dir, "WE", 2) || !ft_strncmp(dir, "EA", 2)))
	{
		(*char_ptr) = save_txt(line, i);
		if (!(*char_ptr))
			return (false);
	}
	else if (!(*int_ptr) && !ft_strncmp(&line[(*i)], dir, 1)
		&& (!ft_strncmp(dir, "F", 1) || !ft_strncmp(dir, "C", 1)))
	{
		(*int_ptr) = save_rgb(line, i);
		if (!(*int_ptr))
			return (false);
	}
	return (true);
}

/// @brief get textures paths and rgb colors
///			or check if the line is valid before getting to the next
/// @param data: data
/// @param line: line
/// @param i: index
/// @return true if success, false otherwise
static bool	get_color_txt(t_data *data, char *line, int *i)
{
	if (!get_info((void *)&data->txt.north_path, "NO", line, i))
		return (error_msg(ERR_TEX_N_INVALID, NULL), false);
	else if (!get_info((void *)&data->txt.south_path, "SO", line, i))
		return (error_msg(ERR_TEX_S_INVALID, NULL), false);
	else if (!get_info((void *)&data->txt.west_path, "WE", line, i))
		return (error_msg(ERR_TEX_W_INVALID, NULL), false);
	else if (!get_info((void *)&data->txt.east_path, "EA", line, i))
		return (error_msg(ERR_TEX_E_INVALID, NULL), false);
	else if (!get_info((void *)&data->txt.floor_rgb, "F", line, i))
		return (error_msg(ERR_COLOR_FLOOR, NULL), false);
	else if (!get_info((void *)&data->txt.ceil_rgb, "C", line, i))
		return (error_msg(ERR_COLOR_CEILING, NULL), false);
	else if (line)
	{
		if (!check_random_line(data, line, (*i)))
			return (false);
		(*i)++;
	}
	return (true);
}

/// @brief skip spaces + parse infos (textures paths + rgb colors)
///			+ check if one texture / rgb is missing
/// @param data: data
/// @param file: file (infos + map)
/// @param row: row
/// @return true if success, false otherwise
bool	parse_infos(t_data *data, char **file, int row)
{
	int		i;

	i = 0;
	if (!data->map.map && (!data->txt.north_path
			|| !data->txt.south_path || !data->txt.west_path
			|| !data->txt.east_path || !data->txt.floor_rgb
			|| !data->txt.ceil_rgb))
	{
		while (file[row][i])
		{
			while (file[row][i]
				&& (ft_isspace(file[row][i])))
				i++;
			if ((row == data->map.line_count - 1)
				&& !check_txt_missing(file[row], i))
				return (false);
			if (file[row][i] && !get_color_txt(data, file[row], &i))
				return (false);
		}
	}
	return (true);
}

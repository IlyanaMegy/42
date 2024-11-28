/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltorkia <ltorkia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:23:47 by ltorkia           #+#    #+#             */
/*   Updated: 2024/05/17 16:43:05 by ltorkia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

/// @brief count the number of lines in the file
/// @param path: path to the file
/// @return number of lines
static int	count_lines(char *path)
{
	int		fd;
	char	*line;
	int		n;

	n = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (error_msg(ERR_OPEN_MAP, NULL), false);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), error_msg(ERR_EMPTY_FILE, NULL), false);
	while (line)
	{
		n++;
		free_ptr(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (n);
}

/// @brief save the file into a char **
/// @param data: data
/// @return true if success, false otherwise
static bool	save_file(t_data *data)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(data->map.fd);
	if (!line)
		return (false);
	while (line)
	{
		data->map.file[i] = ft_strdup(line);
		if (!data->map.file[i])
			return (free_ptr(line), false);
		i++;
		free_ptr(line);
		line = get_next_line(data->map.fd);
	}
	return (true);
}

/// @brief copy the file with all infos into a char **
/// @param data: data
/// @param path: path to the file
/// @return true if success, false otherwise
static bool	copy_file(t_data *data, char *path)
{
	data->map.line_count = count_lines(path);
	if (!data->map.line_count)
		return (false);
	data->map.path = path;
	data->map.file = (char **)
		ft_calloc(data->map.line_count + 1, sizeof(char *));
	if (!data->map.file)
		return (error_msg(ERR_MALLOC, NULL), false);
	data->map.fd = open(data->map.path, O_RDONLY);
	if (data->map.fd < 0)
		return (error_msg(ERR_OPEN_MAP, NULL), false);
	if (!save_file(data))
		return (false);
	close(data->map.fd);
	return (true);
}

/// @brief parse all (copy the file + parse infos + create map)
///			+ check if the map is valid
///			--empty lines (one or more spaces + '\n' alone) are checked
///				and skiped during infos parsing (texture / rgb color)
///			--'\n' alone are allowed (but skipped) between each infos (txt / rgb)
///				but forbidden during map parsing (throw an error)
///			--each texture / rgb is saved before map parsing
///			--check if a texture / rgb is doubled or missing before map parsing
///			--if a random line is found during infos parsing
///				(not a texture, rgb color or empty line), return false
///			--'\n' are removed from the end of each line
///				before saving it (texture / rgb / map)
/// @param data: data
/// @param path: path to the file
/// @return true if success, false otherwise
bool	parse_all(t_data *data, char *path)
{
	int	row;

	row = 0;
	if (!copy_file(data, path))
		return (close(data->map.fd), false);
	while (data->map.file[row])
	{
		if (!check_empty_lines(data, &row, false))
			return (false);
		if (data->map.file[row]
			&& !parse_infos(data, data->map.file, row))
			return (false);
		if (!check_double_txt(data, data->map.file, &row))
			return (false);
		if (data->map.file[row]
			&& !create_map(data, data->map.file, &row))
			return (false);
		if (data->map.file[row])
			row++;
	}
	if (!map_is_valid(data, data->map.map))
		return (false);
	return (true);
}

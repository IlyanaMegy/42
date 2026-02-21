/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltorkia <ltorkia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:23:47 by ltorkia           #+#    #+#             */
/*   Updated: 2024/07/04 17:52:57 by ltorkia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

/// @brief map allocation
///			--skip lines before the map if empty
///			--get max len of the map to make it square when filling lines later
///			--check if map is too small
/// @param data: data
/// @param file: file
/// @param row: row
/// @return true if success, false otherwise
static bool	alloc_map(t_data *data, char **file, int (*row))
{
	if (!check_empty_lines(data, row, true))
		return (false);
	data->map.width = get_max_len(file, (*row));
	data->map.height = data->map.line_count - (*row);
	if (data->map.height < 3)
		return (error_msg(ERR_MAP_TOO_SMALL, NULL), false);
	data->map.map = ft_calloc(data->map.height + 1, sizeof(char *));
	if (!data->map.map)
		return (error_msg(ERR_MALLOC, NULL), false);
	return (true);
}

/// @brief fill short lines with spaces to match map max len
/// @param nmemb: nmemb
/// @param size: size
/// @return ptr
static void	*fill_short_line(size_t nmemb, size_t size)
{
	size_t			i;
	void			*ptr;
	unsigned char	*s;

	if (!size)
		return (NULL);
	ptr = (void *)malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	i = 0;
	s = (unsigned char *)ptr;
	while (i < nmemb * size - 1)
		s[i++] = ' ';
	s[i] = '\0';
	return (ptr);
}

/// @brief fill lines of the map
///			--cut linebreaks
///			--fill short lines with spaces to match map max len
///			or duplicate the line if it's long enough
/// @param data: data
/// @param line: line
/// @param i: map row
/// @return
static bool	fill_lines(t_data *data, char *line, int i)
{
	size_t	extra_size;
	char	*extra_chars;

	cut_linebreak(line);
	if (ft_strlen(line) < (size_t)data->map.width)
	{
		extra_size = (data->map.width - ft_strlen(line)) + 1;
		extra_chars = fill_short_line(sizeof(char), extra_size);
		if (!extra_chars)
			return (error_msg(ERR_MALLOC, NULL), false);
		data->map.map[i] = ft_strjoin(line, extra_chars);
		free_ptr(extra_chars);
	}
	else
		data->map.map[i] = ft_strdup(line);
	if (!data->map.map[i])
		return (error_msg(ERR_INCOMPLETE_MAP, NULL), false);
	return (true);
}

/// @brief create map
///			--check chars validity
///			--check '\n' in map forbidden
/// @param data: data
/// @param file: file
/// @param row: row
/// @return true if success, false otherwise
bool	create_map(t_data *data, char **file, int (*row))
{
	int	i;

	if (data->txt.north_path && data->txt.south_path && data->txt.west_path
		&& data->txt.east_path && data->txt.floor_rgb && data->txt.ceil_rgb)
	{
		i = 0;
		while (file[(*row)])
		{
			if (!data->map.map && !alloc_map(data, file, row))
				return (false);
			(*row) = check_chars(data, file, (*row));
			if ((*row) < 0)
				return (false);
			if (file[(*row)] && !fill_lines(data, file[(*row)], i))
				return (false);
			i++;
			(*row)++;
		}
	}
	return (true);
}

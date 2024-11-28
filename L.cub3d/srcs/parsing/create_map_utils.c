/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltorkia <ltorkia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:23:47 by ltorkia           #+#    #+#             */
/*   Updated: 2024/07/04 17:52:57 by ltorkia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

/// @brief get max len of the map
/// @param file: file
/// @param row: row
/// @return max len
size_t	get_max_len(char **file, int row)
{
	size_t		max;

	max = 0;
	while (file[row])
	{
		if (ft_strlen(file[row]) > max)
		{
			max = ft_strlen(file[row]);
			if (file[row][max - 1] == '\n')
				max--;
		}
		row++;
	}
	return (max);
}

/// @brief check chars validity and '\n' during map parsing.
///			--if '\n' is found at the end of the map, decrease map height
///			and return the index of the last '\n'
///			--if '\n' is found in the middle of the map, return -1
/// @param data: data
/// @param file: file
/// @param row: row
/// @return row index or -1 if invalid char
///			or -1 if '\n' found but not at the end of the map
int	check_chars(t_data *data, char **file, int row)
{
	int		i;
	bool	linebreak_check;

	i = 0;
	linebreak_check = false;
	while (file[row][i])
	{
		if (!ft_strchr(" 01NSWE\n", file[row][i]))
			return (error_msg(ERR_INV_LETTER, NULL), -1);
		i++;
	}
	while (file[row] && ft_strncmp(file[row], "\n", 1) == 0)
	{
		linebreak_check = true;
		data->map.height--;
		row++;
	}
	if (linebreak_check)
	{
		if (file[row])
			return (error_msg(ERR_NEWLINE, NULL), -1);
		return (row - 1);
	}
	return (row);
}

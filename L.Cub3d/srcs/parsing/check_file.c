/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltorkia <ltorkia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:56:00 by ltorkia           #+#    #+#             */
/*   Updated: 2024/07/01 19:04:09 by ltorkia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

/// @brief check if path is a directory
/// @param path: path to check
/// @return true if path is a directory, false otherwise
bool	path_is_dir(char *path)
{
	int	fd;

	fd = open(path, 00200000);
	if (fd >= 0)
		return (close(fd), true);
	return (false);
}

/// @brief check if path exists
/// @param path: path to check
/// @return true if path exists, false otherwise
bool	path_exists(char *path)
{
	int	fd;

	if (path_is_dir(path))
		return (error_msg(ERR_FILE_IS_DIR, NULL), false);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (error_msg(ERR_UNKNOWN_FILE, NULL), false);
	return (close(fd), true);
}

/// @brief check if extension is valid
/// @param path: path to check
/// @param ext: extension to check
/// @return true if extension is valid, false otherwise
bool	extension_is_valid(char *path, char *ext)
{
	size_t	start;
	size_t	extension_len;

	extension_len = ft_strlen(ext);
	start = ft_strlen(path) - extension_len;
	if (ft_strncmp(path + start, ext, extension_len)
		|| path[start - 1] == '/' || !path[start - 1])
		return (false);
	return (true);
}

/// @brief check if file is valid (exists and has the right extension)
/// @param file: file to check
/// @param ext: extension to check
/// @return true if file is valid, false otherwise
bool	file_is_valid(char *file, char *ext)
{
	if (!extension_is_valid(file, ext))
		return (error_msg(ERR_ARGS, ext), false);
	if (!path_exists(file))
		return (false);
	return (true);
}

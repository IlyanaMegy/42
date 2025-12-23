/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltorkia <ltorkia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:03:26 by ltorkia           #+#    #+#             */
/*   Updated: 2024/05/27 15:36:15 by ltorkia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

/// @brief free all data
/// @param data: data to free
static void	free_infos(t_data *data)
{
	if (data->txt.north_path)
		free_ptr(data->txt.north_path);
	if (data->txt.south_path)
		free_ptr(data->txt.south_path);
	if (data->txt.west_path)
		free_ptr(data->txt.west_path);
	if (data->txt.east_path)
		free_ptr(data->txt.east_path);
	if (data->txt.floor_rgb)
		free_ptr(data->txt.floor_rgb);
	if (data->txt.ceil_rgb)
		free_ptr(data->txt.ceil_rgb);
	return ;
}

/// @brief free all double array string
/// @param data: data to free
static void	free_map(t_data *data)
{
	if (data->map.file)
		free_tab((void **)data->map.file);
	if (data->map.map)
		free_tab((void **)data->map.map);
	if (data->textures)
		free_tab((void **)data->textures);
	if (data->texture_pixels)
		free_tab((void **)data->texture_pixels);
	return ;
}

/// @brief free all data + destroy mlx window
/// @param data: data to free
void	clean_program(t_data *data)
{
	if (data)
	{
		destroy_window(data);
		free_infos(data);
		free_map(data);
	}
}

/// @brief destroy mlx window
/// @param data: data to free
void	destroy_window(t_data *data)
{
	if (data->minimap.img)
		mlx_destroy_image(data->mlx_ptr, data->minimap.img);
	if (data->mlx_ptr && data->win_ptr)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	}
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		mlx_loop_end(data->mlx_ptr);
		free_ptr(data->mlx_ptr);
	}
}

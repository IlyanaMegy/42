/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:05:25 by ilymegy           #+#    #+#             */
/*   Updated: 2024/05/15 18:05:26 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	init_texture_pixels(t_data *data)
{
	int	i;

	if (data->texture_pixels)
		free_tab((void **)data->texture_pixels);
	data->texture_pixels = ft_calloc(data->win_height + 1,
			sizeof * data->texture_pixels);
	if (!data->texture_pixels)
		error_exit(ERR_MALLOC, data);
	i = 0;
	while (i < data->win_height)
	{
		data->texture_pixels[i++] = ft_calloc(data->win_height + 1,
				sizeof data->texture_pixels);
		if (!data->texture_pixels)
			error_exit(ERR_MALLOC, data);
	}
}

static void	get_texture_index(t_data *data, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir_x < 0)
			data->txt.index = WEST;
		else
			data->txt.index = EAST;
	}
	else
	{
		if (ray->dir_y > 0)
			data->txt.index = SOUTH;
		else
			data->txt.index = NORTH;
	}
}

void	update_texture_pixels(t_data *data, t_txt *tex, t_ray *ray, int x)
{
	int	y;
	int	color;

	get_texture_index(data, ray);
	tex->x = (int)(ray->wall_x * tex->size);
	if ((ray->side == 0 && ray->dir_x < 0) || (ray->side == 1
			&& ray->dir_y > 0))
		tex->x = tex->size - tex->x - 1;
	tex->step = 1.0 * tex->size / ray->line_height;
	tex->pos = (ray->draw_start - data->win_height / 2 + ray->line_height / 2)
		* tex->step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		tex->y = (int)tex->pos & (tex->size - 1);
		tex->pos += tex->step;
		color = data->textures[tex->index][tex->size * tex->y + tex->x];
		if (tex->index == NORTH || tex->index == EAST)
			color = (color >> 1) & 8355711;
		if (color > 0)
			data->texture_pixels[y][x] = color;
		y++;
	}
}

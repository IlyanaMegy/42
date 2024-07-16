/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_pixels.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltorkia <ltorkia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:27:12 by ilymegy           #+#    #+#             */
/*   Updated: 2024/07/03 06:59:28 by ltorkia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	set_circle_pixels(t_img *img, int x_center,
	int y_center, int radius)
{
	int	x;
	int	y;

	y = -radius;
	while (y <= radius)
	{
		x = -radius;
		while (x <= radius)
		{
			if (x * x + y * y <= radius * radius)
				set_image_pixel(img, x_center + x,
					y_center + y, MMAP_COLOR_PLAYER);
			x++;
		}
		y++;
	}
}

void	set_minimap_tile_pixels(t_minimap *minimap, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < minimap->tile_size)
	{
		j = 0;
		while (j < minimap->tile_size)
		{
			set_image_pixel(minimap->img, x + j, i + y, color);
			j++;
		}
		i++;
	}
}

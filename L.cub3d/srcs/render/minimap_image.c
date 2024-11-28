/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltorkia <ltorkia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:27:12 by ilymegy           #+#    #+#             */
/*   Updated: 2024/07/04 16:29:31 by ltorkia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	draw_minimap_tile(t_minimap *minimap, int x, int y)
{
	if (minimap->map[y][x] == 'P')
	{
		set_minimap_tile_pixels(minimap, x * minimap->tile_size, y
			* minimap->tile_size, MMAP_COLOR_FLOOR);
		set_circle_pixels(minimap->img,
			x * minimap->tile_size + minimap->tile_size / 2,
			y * minimap->tile_size + minimap->tile_size / 2,
			minimap->tile_size / 2);
	}
	else if (minimap->map[y][x] == '1')
		set_minimap_tile_pixels(minimap, x * minimap->tile_size, y
			* minimap->tile_size, MMAP_COLOR_WALL);
	else if (minimap->map[y][x] == '0')
		set_minimap_tile_pixels(minimap, x * minimap->tile_size, y
			* minimap->tile_size, MMAP_COLOR_FLOOR);
	else if (minimap->map[y][x] == ' ')
		set_minimap_tile_pixels(minimap, x * minimap->tile_size, y
			* minimap->tile_size, MMAP_COLOR_SPACE);
}

static void	set_minimap_border_image_pixels(t_minimap *minimap, int color)
{
	int	size;
	int	x;
	int	y;

	size = MMAP_PIXEL_SIZE + minimap->tile_size;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x <= size)
		{
			if (x < 5 || x > size - 5 || y < 5 || y > size - 5)
				set_image_pixel(minimap->img, x, y, color);
			x++;
		}
		y++;
	}
}

static void	draw_minimap(t_minimap *minimap)
{
	int	x;
	int	y;

	y = 0;
	while (y < minimap->size)
	{
		x = 0;
		while (x < minimap->size)
		{
			if (!minimap->map[y] || !minimap->map[y][x]
				|| minimap->map[y][x] == '\0')
				break ;
			draw_minimap_tile(minimap, x, y);
			x++;
		}
		y++;
	}
	set_minimap_border_image_pixels(minimap, MMAP_COLOR_SPACE);
}

void	render_minimap_image(t_data *data, t_minimap *minimap)
{
	draw_minimap(minimap);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->minimap.img,
		minimap->tile_size,
		data->win_height - (MMAP_PIXEL_SIZE + (minimap->tile_size * 2)));
	free_tab((void **)minimap->map);
}

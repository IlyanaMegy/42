/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:22:58 by ilymegy           #+#    #+#             */
/*   Updated: 2024/05/14 13:23:00 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	init_img(t_data *data, t_img *image, int width, int height)
{
	init_img_clean(image);
	image->img = mlx_new_image(data->mlx_ptr, width, height);
	if (image->img == NULL)
		error_exit(ERR_MLX_IMG, data);
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
}

static void	init_texture_img(t_data *data, t_img *image, char *path)
{
	init_img_clean(image);
	image->img = mlx_xpm_file_to_image(data->mlx_ptr, path, &data->txt.size,
			&data->txt.size);
	if (image->img == NULL)
		error_exit(ERR_MLX_IMG, data);
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
}

static int	*xpm_to_img(t_data *data, char *path)
{
	t_img	tmp;
	int		*buffer;
	int		x;
	int		y;

	init_texture_img(data, &tmp, path);
	buffer = ft_calloc(1, sizeof * buffer * data->txt.size * data->txt.size);
	if (!buffer)
		error_exit(ERR_MALLOC, data);
	y = 0;
	while (y < data->txt.size)
	{
		x = 0;
		while (x < data->txt.size)
		{
			buffer[y * data->txt.size + x] = tmp.addr[y * data->txt.size + x];
			++x;
		}
		y++;
	}
	mlx_destroy_image(data->mlx_ptr, tmp.img);
	return (buffer);
}

static unsigned long	convert_rgb_to_hex(int *rgb_tab)
{
	unsigned long	result;
	int				r;
	int				g;
	int				b;

	r = rgb_tab[0];
	g = rgb_tab[1];
	b = rgb_tab[2];
	result = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
	return (result);
}

void	init_textures(t_data *data)
{
	data->textures = ft_calloc(5, sizeof * data->textures);
	if (!data->textures)
		error_exit(ERR_MALLOC, data);
	data->txt.size = TEX_SIZE;
	data->txt.hex_ceiling = convert_rgb_to_hex(data->txt.ceil_rgb);
	data->txt.hex_floor = convert_rgb_to_hex(data->txt.floor_rgb);
	data->textures[NORTH] = xpm_to_img(data, data->txt.north_path);
	data->textures[SOUTH] = xpm_to_img(data, data->txt.south_path);
	data->textures[EAST] = xpm_to_img(data, data->txt.east_path);
	data->textures[WEST] = xpm_to_img(data, data->txt.west_path);
}

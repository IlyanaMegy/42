/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltorkia <ltorkia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:22:15 by ilymegy           #+#    #+#             */
/*   Updated: 2024/05/27 15:38:24 by ltorkia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static int	get_mmap_offset(t_minimap *minimap, int mapsize, int pos)
{
	if (pos > minimap->view_dist && mapsize - pos > minimap->view_dist + 1)
		return (pos - minimap->view_dist);
	if (pos > minimap->view_dist && mapsize - pos <= minimap->view_dist + 1)
		return (mapsize - minimap->size);
	return (0);
}

static bool	is_valid_map_coord(int coord, int size)
{
	if (coord < size)
		return (true);
	return (false);
}

static char	*add_minimap_line(t_data *d, t_minimap *m, int y)
{
	char	*line;
	int		x;

	line = ft_calloc(m->size + 1, sizeof * line);
	if (!line)
		return (NULL);
	x = 0;
	while (x < m->size && x < d->map.width)
	{
		if (!is_valid_map_coord(y + m->offset_y, d->map.height)
			|| !is_valid_map_coord(x + m->offset_x, d->map.width))
			line[x] = '\0';
		else if ((int)d->player.pos_x == (x + m->offset_x)
			&& (int)d->player.pos_y == (y + m->offset_y))
			line[x] = 'P';
		else if (d->map.map[y + m->offset_y][x + m->offset_x] == '1')
			line[x] = '1';
		else if (d->map.map[y + m->offset_y][x + m->offset_x] == '0')
			line[x] = '0';
		else
			line[x] = '\0';
		x++;
	}
	return (line);
}

static char	**generate_minimap(t_data *data, t_minimap *minimap)
{
	char	**mmap;
	int		y;

	mmap = ft_calloc(minimap->size + 1, sizeof * mmap);
	if (!mmap)
		return (NULL);
	y = 0;
	while (y < minimap->size && y < data->map.height)
	{
		mmap[y] = add_minimap_line(data, minimap, y);
		if (!mmap[y])
			return (free_tab((void **)mmap), NULL);
		y++;
	}
	return (mmap);
}

void	render_minimap(t_data *data)
{
	static t_minimap	minimap = {0};
	int					img_size;
	char				**new_map;

	if (!minimap.img)
	{
		minimap.view_dist = MMAP_VIEW_DIST;
		minimap.size = (2 * minimap.view_dist) + 1;
		minimap.tile_size = MMAP_PIXEL_SIZE / (2 * minimap.view_dist);
		img_size = MMAP_PIXEL_SIZE + minimap.tile_size;
		init_img(data, &data->minimap, img_size, img_size);
		minimap.img = &data->minimap;
	}
	minimap.offset_x = get_mmap_offset(&minimap,
			data->map.width, (int)data->player.pos_x);
	minimap.offset_y = get_mmap_offset(&minimap,
			data->map.height, (int)data->player.pos_y);
	new_map = generate_minimap(data, &minimap);
	if (!new_map)
		error_exit(ERR_MALLOC, data);
	minimap.map = new_map;
	if (MMAP_DEBUG_MSG)
		debug_display_minimap(&minimap);
	render_minimap_image(data, &minimap);
}

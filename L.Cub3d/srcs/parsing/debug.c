/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltorkia <ltorkia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 21:01:44 by ltorkia           #+#    #+#             */
/*   Updated: 2024/07/02 06:49:18 by ltorkia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"
#include <stdio.h>

static void	debug_print_char_tab(char **tab)
{
	int	i;

	printf("\n");
	i = 0;
	while (tab[i])
		printf("%s\n", tab[i++]);
	printf("\n");
}

void	debug_display_minimap(t_minimap *minimap)
{
	printf(YELLOW "\n---- MINIMAP\n" RESET);
	printf("Minimap view distance: %d\n", minimap->view_dist);
	printf("Minimap size: %d * %d\n", minimap->size, minimap->size);
	debug_print_char_tab(minimap->map);
}

static void	print_loops(t_data *data)
{
	int	len;

	len = 0;
	while (len < 3 && data)
	{
		printf("floor_rgb_rgb[%d] = %d\n", len, data->txt.floor_rgb[len]);
		len++;
	}
	len = 0;
	while (len < 3 && data)
	{
		printf("ceil_rgb_rgb[%d] = %d\n", len, data->txt.ceil_rgb[len]);
		len++;
	}
	return ;
}

void	print_data(t_data *data)
{
	printf("win_height = %d\n", data->win_height);
	printf("win_width = %d\n", data->win_width);
	printf("player_row = %f\n", data->player.pos_x);
	printf("player_column = %f\n", data->player.pos_y);
	printf("player.dir = %c\n", data->player.dir);
	printf("north_path = %s\n", data->txt.north_path);
	printf("south_path = %s\n", data->txt.south_path);
	printf("west_path = %s\n", data->txt.west_path);
	printf("east_path = %s\n", data->txt.east_path);
	print_loops(data);
	printf("map.path = %s\n", data->map.path);
	printf("map.fd = %d\n", data->map.fd);
	printf("map.height = %d\n", data->map.height);
	printf("map.width = %i\n", data->map.width);
	printf("map.line_count = %d\n\n", data->map.line_count);
	return ;
}

void	print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	return ;
}

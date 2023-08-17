/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:33:42 by ilymegy           #+#    #+#             */
/*   Updated: 2023/07/28 17:33:44 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	img_on_map(char p, int x, int y, t_game *g)
{
	if (p == '1')
		mlx_put_image_to_window(g->mlx_ptr, g->mlx_win, g->wall_img, x, y);
	else if (p == 'C')
		mlx_put_image_to_window(g->mlx_ptr, g->mlx_win, g->collec_img, x, y);
	else if (p == 'E')
		mlx_put_image_to_window(g->mlx_ptr, g->mlx_win, g->exit_img, x, y);
	else if (p == 'P')
	{
		g->y_p = y;
		g->x_p = x;
		mlx_put_image_to_window(g->mlx_ptr, g->mlx_win, g->main_img_d, x, y);
	}
	else if (p == 'B')
		mlx_put_image_to_window(g->mlx_ptr, g->mlx_win, g->enemy_img, x, y);
	else
		mlx_put_image_to_window(g->mlx_ptr, g->mlx_win, g->bg_img, x, y);
}

void	init_img(t_game *game)
{
	game->wall_img = save_that_img("./img/wall.xpm", game);
	game->enemy_img = save_that_img("./img/spider1.xpm", game);
	game->main_img_d = save_that_img("./img/down.xpm", game);
	game->main_img_u = save_that_img("./img/up.xpm", game);
	game->main_img_l = save_that_img("./img/left.xpm", game);
	game->main_img_r = save_that_img("./img/right.xpm", game);
	game->exit_img = save_that_img("./img/exit.xpm", game);
	game->collec_img = save_that_img("./img/apple.xpm", game);
	game->bg_img = save_that_img("./img/bg.xpm", game);
}

void	update_values(int *map_x, int *x, int *map_size_x)
{
	(*map_x)++;
	*x += 50;
	(*map_size_x)--;
}

void	render_map(t_game *game)
{
	int	y;
	int	x;
	int	map_y;
	int	map_x;
	int	tmp_w;

	y = 0;
	map_y = 0;
	tmp_w = game->map_size.x;
	init_img(game);
	while (game->map_size.y > 0)
	{
		x = 0;
		map_x = 0;
		while (game->map_size.x > 0)
		{
			img_on_map(game->map[map_y][map_x], x, y, game);
			update_values(&map_x, &x, &game->map_size.x);
		}
		game->map_size.x = tmp_w;
		map_y++;
		y += 50;
		game->map_size.y--;
	}
}

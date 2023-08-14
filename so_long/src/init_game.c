/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:12:01 by ilymegy           #+#    #+#             */
/*   Updated: 2023/07/28 17:12:03 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	init_vars(t_game *game)
{
	game->map_size.x = ft_strlen(game->map[0]);
	game->map_size.y = get_height(game->map);
	game->nb_c = 0;
	game->moves = 0;
}

int	key_check(int keycode, t_game *game)
{
	int	x;
	int	y;

	x = game->p_pos.x;
	y = game->p_pos.y;
	if (keycode == XK_Escape)
		end_game("", game, event_end, NULL);
	else if (keycode == XK_a && !is_wall(game, y, x - 1))
		move_to(x - 1, y, "./img/left.xpm", game);
	else if (keycode == XK_d && !is_wall(game, y, x + 1))
		move_to(x + 1, y, "./img/right.xpm", game);
	else if (keycode == XK_w && !is_wall(game, y - 1, x))
		move_to(x, y - 1, "./img/up.xpm", game);
	else if (keycode == XK_s && !is_wall(game, y + 1, x))
		move_to(x, y + 1, "./img/down.xpm", game);
	return (0);
}

void	init_game(t_game *game, char *map_file)
{
	int	x;
	int	y;

	(void)map_file;
	game->map = get_map(map_file, game);
	if (game->map != NULL)
	{
		// show_table(game->map);
		init_vars(game);
		check_map_valid(game, map_file);
		game->mlx_ptr = mlx_init();
		if (!game->mlx_ptr)
			end_game("Fail init mlx.", game, map_error, NULL);
		y = game->map_size.y;
		x = game->map_size.x;
		game->mlx_win = mlx_new_window(game->mlx_ptr, x * 50, y * 50, "GAME");
		if (!game->mlx_win)
			end_game("Fail creating window.", game, map_error, game->mlx_ptr);
		render_map(game);
		mlx_hook(game->mlx_win, KEY_RELEASED, KEY_MASK, key_check, game);
		mlx_hook(game->mlx_win, ON_DESTROY, EXIT_MASK, exit_event, game);
		mlx_loop(game->mlx_ptr);
	}
	end_game("An error occurred while saving the map.", game, file_error, NULL);
}

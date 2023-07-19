/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <ilyanamegy@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 09:25:39 by ilymegy           #+#    #+#             */
/*   Updated: 2023/07/19 13:27:06 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void init_vars(t_game *game)
{
	game->win_w = ft_strlen(game->map[0]);
	game->win_h = get_height(game->map);
}

int key_check(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		end_game("", game, event_end);
	else if (keycode == XK_a || keycode == XK_Left)
		ft_printf("left !\n");
	else if (keycode == XK_d || keycode == XK_Right)
		ft_printf("right !\n");
	else if (keycode == XK_w || keycode == XK_Up)
		ft_printf("up !\n");
	else if (keycode == XK_s || keycode == XK_Down)
		ft_printf("down !\n");
	// 	ft_printf("code : %d\n", keycode);
	return (0);
}

static void init_game(t_game *game, char *map_file)
{
	// save map in game->map and check the map
	(void)map_file;
	get_map(map_file, game);
	// ft_printf("second line is :\n%s\n", (game->map)[1]);
	if (game->map != NULL)
	{
		check_map_rect(game);
		check_map_walls(game);
		check_map_elem(game);
		ft_printf("Completed check-in, we can start now!\nControls :\nArrows : up, left, down, right.\nKeyboard : W,A,S,D.\nESC to quit.\n");
		init_vars(game);
		game->mlx_ptr = mlx_init();
		ft_printf("width = %d * 100, height = %d * 100\n", game->win_w, game->win_h);
		game->mlx_win = mlx_new_window(game->mlx_ptr, game->win_w * 100, game->win_h * 100, "Event Parameters");
		show_table(game);
		render_map(game);
		
		// init images
		mlx_hook(game->mlx_win, KEY_RELEASED, KEY_RELEASED_MASK, key_check, game);
		mlx_hook(game->mlx_win, ON_DESTROY, NO_EVENT_MASK, exit_event, game);
		mlx_loop(game->mlx_ptr);
	}
}

static int is_ber_file(const char *av)
{
	char *string;

	string = ft_strrchr(av, '.');
	if (string)
		return (ft_strcmp(string, ".ber") == 0);
	return (1);
}

int main(int ac, char **av)
{
	t_game game;

	if (ac == 2 && (is_ber_file(av[1])))
		init_game(&game, av[1]);
	else if (ac == 2 && !(is_ber_file(av[1])))
		end_game("Can't open file. The format is not supported!", &game, error);
	else if (ac > 2)
		end_game("Can't open multiple files!", &game, error);
	else if (ac < 2)
		end_game("Invalid number of arguments : Missing .ber file!\nExit game bye.", &game, error);
	else
		end_game("Please specify file name!", &game, error);
	return (0);
}

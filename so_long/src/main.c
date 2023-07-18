/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <ilyanamegy@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 09:25:39 by ilymegy           #+#    #+#             */
/*   Updated: 2023/07/16 21:59:37 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
	// else
	// 	ft_printf("code : %d\n", keycode);
	return (0);
}

static void init_hook(t_game *game, int event, int mask, int (*f)())
{
	mlx_hook(game->mlx_win, event, mask, f, game);
}

static void init_game(t_game *game, char *map_file)
{
	(void)map_file;
	get_map(map_file, game);
	ft_printf("first line is :\n%s\n", (game->map)[0]);
	game->mlx_ptr = mlx_init();
	// init win
	game->mlx_win = mlx_new_window(game->mlx_ptr, 1000, 500, "Event Parameters");
	// init images
	// key hook event
	init_hook(game, KEY_RELEASED, KEY_RELEASED_MASK, key_check);
	// exit hook event
	init_hook(game, ON_DESTROY, NO_EVENT_MASK, exit_event);
	mlx_loop(game->mlx_ptr);
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
	end_game("Please specify file name!", &game, error);
	return (0);
}

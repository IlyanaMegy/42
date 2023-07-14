/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 09:25:39 by ilymegy           #+#    #+#             */
/*   Updated: 2023/07/14 09:25:46 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
<<<<<<< HEAD
=======
#include "mlx.h"

#include "../inc/libft.h"

void	destroy_the(t_game *game)
{
	// mlx_destroy_image(game->mlx_pointer, game->wall.ptr);
	// mlx_destroy_image(game->mlx_pointer, game->floor.ptr);
	// mlx_destroy_image(game->mlx_pointer, game->portal.ptr);
	// [...]
	mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	mlx_destroy_display(game->mlx_ptr);
	// free_map(game);
	free(game->mlx_ptr);
	return ;
}

void	end_game(char *msg, t_game *game, enum e_state state)
{
	if (state == event_end)
	{
		ft_printf("%s\n", msg);
		destroy_the(game);
		exit(0);
		return ;
	}
	ft_printf("Error\n%s\n" RED, msg);
	destroy_the(game);
	exit(1);
	return ;
}
>>>>>>> 0a3331fb9ced29dc6d5a312dd866b348e4ddfd9c

int	exit_event(t_game *game)
{
	end_game("closing the window...", game, event_end);
	return (0);
}

<<<<<<< HEAD
int	key_check(int keycode, t_game *game)
{
	if (keycode == ESC)
		end_game("", game, event_end);
	else if (keycode == LEFT)
		ft_printf("left !\n");
	else if (keycode == RIGHT)
		ft_printf("right !\n");
	else if (keycode == UP)
		ft_printf("up !\n");
	else if (keycode == DOWN)
		ft_printf("down !\n");
	return (0);
}

=======
>>>>>>> 0a3331fb9ced29dc6d5a312dd866b348e4ddfd9c
static void	init_hook(t_game *game, int event, int mask, int (*f)())
{
	mlx_hook(game->mlx_win, event, mask, f, game);
}

static void	init_game(t_game *game)
{
	game->mlx_ptr = mlx_init();
	// init win
	game->mlx_win = mlx_new_window(game->mlx_ptr, 640, 360, "Event Parameters");
<<<<<<< HEAD
	// init images
	// key hook event
	init_hook(game, KEY_RELEASED, KEY_RELEASED_MASK, key_check);
	// exit hook event
=======
>>>>>>> 0a3331fb9ced29dc6d5a312dd866b348e4ddfd9c
	init_hook(game, ON_DESTROY, NO_EVENT_MASK, exit_event);
	mlx_loop(game->mlx_ptr);
}

int	main(void)
{
<<<<<<< HEAD
	t_game	game;

	// check args, check is it .ber in arg
=======
	t_game game;
>>>>>>> 0a3331fb9ced29dc6d5a312dd866b348e4ddfd9c
	init_game(&game);
	return (0);
}

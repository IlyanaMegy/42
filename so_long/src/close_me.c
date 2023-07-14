/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_me.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 09:48:22 by ilymegy           #+#    #+#             */
/*   Updated: 2023/07/14 09:48:24 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../inc/so_long.h"

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
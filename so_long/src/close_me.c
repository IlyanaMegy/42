/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_me.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <ilyanamegy@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 09:48:22 by ilymegy           #+#    #+#             */
/*   Updated: 2023/07/20 17:36:44 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../inc/so_long.h"

int exit_event(t_game *game)
{
	end_game("closing the window...", game, event_end);
	return (0);
}

void free_map(char **map)
{
	int i;
	i = 0;
	// char *tmp;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return;
}

void destroy_the(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->wall_img);
	mlx_destroy_image(game->mlx_ptr, game->bg_img);
	// mlx_destroy_image(game->mlx_ptr, game->wong_img);
	mlx_destroy_image(game->mlx_ptr, game->rick_img);
	mlx_destroy_image(game->mlx_ptr, game->collec_img);
	mlx_destroy_image(game->mlx_ptr, game->exit_img);

	mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	mlx_destroy_display(game->mlx_ptr);
	free_map(game->map);
	free(game->mlx_ptr);
	return;
}

void end_game(char *msg, t_game *game, enum e_state state)
{
	if (state == event_end)
	{
		ft_printf("%s\n" RED, msg);
		destroy_the(game);
		exit(0);
		return;
	}
	else if (state == file_error || state == error)
	{
		ft_printf("Error\n%s\n" RED, msg);
		exit(1);
	}
	ft_printf("Error\n%s\n" RED, msg);
	destroy_the(game);
	exit(1);
	return;
}
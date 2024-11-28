/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:41:32 by ilymegy           #+#    #+#             */
/*   Updated: 2024/05/15 15:41:33 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static int	key_press_handler(int key, t_data *data)
{
	if (key == XK_Escape)
		exit_game(data, 0);
	if (key == XK_Left)
		data->player.rotate -= 1;
	if (key == XK_Right)
		data->player.rotate += 1;
	if (key == XK_w)
		data->player.move_y = 1;
	if (key == XK_a)
		data->player.move_x = -1;
	if (key == XK_s)
		data->player.move_y = -1;
	if (key == XK_d)
		data->player.move_x = 1;
	return (0);
}

static int	key_release_handler(int key, t_data *data)
{
	if (key == XK_Escape)
		exit_game(data, 0);
	if (key == XK_w && data->player.move_y == 1)
		data->player.move_y = 0;
	if (key == XK_s && data->player.move_y == -1)
		data->player.move_y = 0;
	if (key == XK_a && data->player.move_x == -1)
		data->player.move_x += 1;
	if (key == XK_d && data->player.move_x == 1)
		data->player.move_x -= 1;
	if (key == XK_Left && data->player.rotate <= 1)
		data->player.rotate = 0;
	if (key == XK_Right && data->player.rotate >= -1)
		data->player.rotate = 0;
	return (0);
}

static int	mouse_motion_handler(int x, int y, t_data *data)
{
	static int	old_x;

	old_x = WIN_WIDTH / 2;
	if (!data->use_mouse)
		return (0);
	if (x > data->win_width - DIST_EDGE_MOUSE_WRAP)
	{
		x = DIST_EDGE_MOUSE_WRAP;
		mlx_mouse_move(data->mlx_ptr, data->win_ptr, x, y);
	}
	if (x < DIST_EDGE_MOUSE_WRAP)
	{
		x = data->win_width - DIST_EDGE_MOUSE_WRAP;
		mlx_mouse_move(data->mlx_ptr, data->win_ptr, x, y);
	}
	if (x == old_x)
		return (0);
	else if (x < old_x)
		data->player.has_moved += rotate_player(data, -1);
	else if (x > old_x)
		data->player.has_moved += rotate_player(data, 1);
	old_x = x;
	return (0);
}

static int	mouse_click_handler(int key, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	(void)data;
	if (key == 1 && data->use_mouse)
		data->use_mouse = 0;
	else if (key == 1 && !data->use_mouse)
		data->use_mouse = 1;
	return (0);
}

void	inputs(t_data *data)
{
	mlx_hook(data->win_ptr, ClientMessage, NoEventMask, exit_game, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, key_press_handler, data);
	mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask, key_release_handler,
		data);
	mlx_hook(data->win_ptr, ButtonPress, ButtonPressMask, mouse_click_handler,
		data);
	if (MINIMAP)
		mlx_hook(data->win_ptr, MotionNotify, PointerMotionMask,
			mouse_motion_handler, data);
}

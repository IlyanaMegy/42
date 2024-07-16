/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:53:22 by ilymegy           #+#    #+#             */
/*   Updated: 2024/05/17 12:53:23 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static bool	is_valid_pos_wall_collision(t_data *data, double x, double y)
{
	if (data->map.map[(int)y][(int)x] == '0')
		return (true);
	return (false);
}

static bool	is_valid_pos_in_map(t_data *data, double x, double y)
{
	if (x < 0.25 || x > data->map.width - 1.25)
		return (false);
	if (y < 0.25 || y > data->map.height -0.25)
		return (false);
	return (true);
}

static bool	is_valid_pos(t_data *data, double x, double y)
{
	if (!MINIMAP && is_valid_pos_in_map(data, x, y))
		return (true);
	if (MINIMAP && is_valid_pos_wall_collision(data, x, y))
		return (true);
	return (false);
}

int	validate_move(t_data *data, double new_x, double new_y)
{
	int	moved;

	moved = 0;
	if (is_valid_pos(data, new_x, data->player.pos_y))
	{
		data->player.pos_x = new_x;
		moved = 1;
	}
	if (is_valid_pos(data, data->player.pos_x, new_y))
	{
		data->player.pos_y = new_y;
		moved = 1;
	}
	return (moved);
}

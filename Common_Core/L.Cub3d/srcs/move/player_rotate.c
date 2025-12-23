/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:00:49 by ilymegy           #+#    #+#             */
/*   Updated: 2024/05/17 13:00:50 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static int	rotate_left_right(t_data *data, double rotspeed)
{
	t_player	*p;
	double		tmp_x;

	p = &data->player;
	tmp_x = p->dir_x;
	p->dir_x = p->dir_x * cos(rotspeed) - p->dir_y * sin(rotspeed);
	p->dir_y = tmp_x * sin(rotspeed) + p->dir_y * cos(rotspeed);
	tmp_x = p->plane_x;
	p->plane_x = p->plane_x * cos(rotspeed) - p->plane_y * sin(rotspeed);
	p->plane_y = tmp_x * sin(rotspeed) + p->plane_y * cos(rotspeed);
	return (1);
}

//!\\ replace 0.01 to ROTSPEED
int	rotate_player(t_data *data, double rotdir)
{
	int		moved;
	double	rotspeed;

	moved = 0;
	rotspeed = ROTSPEED * rotdir;
	moved += rotate_left_right(data, rotspeed);
	return (moved);
}

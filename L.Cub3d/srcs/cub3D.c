/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltorkia <ltorkia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:56:00 by ltorkia           #+#    #+#             */
/*   Updated: 2024/07/02 04:18:56 by ltorkia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	init_program(t_data *data)
{
	ft_memset(data, 0, sizeof(t_data));
	data->win_height = WIN_HEIGHT;
	data->win_width = WIN_WIDTH;
	ft_memset(&data->player, 0, sizeof(t_player));
	ft_memset(&data->map, 0, sizeof(t_map));
	data->map.map = NULL;
	ft_memset(&data->txt, 0, sizeof(t_txt));
	data->txt.floor_rgb = NULL;
	data->txt.ceil_rgb = NULL;
	data->use_mouse = 1;
	init_img_clean(&data->minimap);
}

void	init_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		error_exit(ERR_MLX_INIT, data);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_width,
			data->win_height, "GAME");
	if (!data->win_ptr)
		error_exit(ERR_MLX_WIN, data);
	if (MINIMAP)
		mlx_mouse_move(data->mlx_ptr, data->win_ptr, data->win_width / 2,
			data->win_height / 2);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (error_msg(ERR_ARGS, ERR_USAGE), false);
	if (!file_is_valid(av[1], ".cub"))
		return (EXIT_FAILURE);
	init_program(&data);
	if (!parse_all(&data, av[1]))
		return (clean_program(&data), EXIT_FAILURE);
	init_player_direction(&data);
	init_mlx(&data);
	init_textures(&data);
	render_images(&data);
	inputs(&data);
	mlx_loop_hook(data.mlx_ptr, render, &data);
	mlx_loop(data.mlx_ptr);
	return (clean_program(&data), EXIT_SUCCESS);
}

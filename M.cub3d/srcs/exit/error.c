/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltorkia <ltorkia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:56:00 by ltorkia           #+#    #+#             */
/*   Updated: 2024/05/06 19:25:31 by ltorkia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

/// @brief if ptr doesn't exist display error message and exit
/// @param data: data to free
/// @param ptr: check if ptr exists
/// @param err_msg: error message to display
void	check_alloc(t_data *data, void *ptr, char *err_msg)
{
	if (!ptr)
	{
		if (data->map.fd > 0)
			close(data->map.fd);
		error_msg(err_msg, NULL);
		exit_game(data, EXIT_FAILURE);
	}
}

/// @brief display error message
/// @param error_type: error type
/// @param usage: usage message
void	error_msg(char *error_type, char *usage)
{
	ft_putstr_fd(RED BOLD "\nError\n" RESET, 2);
	ft_putstr_fd(YELLOW ITALIC, 2);
	ft_putstr_fd("--", 2);
	ft_putstr_fd(error_type, 2);
	ft_putstr_fd("\n" RESET, 2);
	if (usage)
	{
		ft_putstr_fd(GREEN, 2);
		ft_putstr_fd("--Required: ", 2);
		ft_putstr_fd(usage, 2);
		ft_putstr_fd("\n" RESET, 2);
	}
	ft_putstr_fd("\n", 2);
}

/// @brief display error message and exit
/// @param str: error message
/// @param data: data to free
void	error_exit(char *str, t_data *data)
{
	error_msg(str, NULL);
	exit_game(data, EXIT_FAILURE);
}

/// @brief free all malloc data and exit
/// @param data: data to free
/// @param status: exit status
int	exit_game(t_data *data, int status)
{
	clean_program(data);
	exit(status);
	return (0);
}

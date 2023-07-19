/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <ilyanamegy@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 09:25:39 by ilymegy           #+#    #+#             */
/*   Updated: 2023/07/19 13:54:23 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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

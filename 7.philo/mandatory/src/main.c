/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 11:15:12 by ilymegy           #+#    #+#             */
/*   Updated: 2023/11/18 11:15:17 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int	main(int ac, char **av)
{
	t_main	main;
		
	// printf("nb = %d, av[%d] = %s\n", ac, ac - 1, av[ac - 1]);
	if (!check_args(ac, av, &main))
		return (1);
	return (0);
}

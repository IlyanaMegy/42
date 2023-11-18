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

	if (check_args(ac, av, &main))
		return (1);
	if (init_philos(&main))
		return (1);
	return (0);
}

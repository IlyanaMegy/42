/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:53:50 by ilymegy           #+#    #+#             */
/*   Updated: 2023/11/18 18:53:52 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	fill_philo_struct(t_main *main, int i, int j)
{
	main->philo[i].id = i + 1;
	main->philo[i].nb_of_times_ate = 0;
	main->philo[i].ttd = 0;
	main->philo[i].fork.left = i;
	main->philo[i].fork.right = j;
}

int	init_philos(t_main *main)
{
	int	i;
	int	j;

	main->philo = malloc(sizeof(t_philo) * (main->input.nb_philo + 1));
	if (main->philo == NULL)
		return (1);
	i = 0;
	j = 1;
	while (j < main->input.nb_philo)
	{
		fill_philo_struct(main, i, j);
		i++;
		j++;
	}
	j = 0;
	fill_philo_struct(main, i, j);
	return (0);
}

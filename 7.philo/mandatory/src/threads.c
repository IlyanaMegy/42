/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:22:26 by ilymegy           #+#    #+#             */
/*   Updated: 2023/11/19 14:22:27 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int	join_threads(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->input.nb_philo)
	{
		if (pthread_join(main->philo[i].thread, NULL) != 0)
			return (1);
		i++;
	}
	if (pthread_join(main->monitor, NULL) != 0)
		return (1);
	return (0);
}

int	init_threads(t_main *main)
{
	int	i;

	main->philo_dead = 0;
	main->t0 = get_time();
	if (pthread_mutex_init(&main->write, NULL) != 0)
		return (1);
	i = 0;
	while (i < main->input.nb_philo)
	{
		main->n_thread = i;
		if (pthread_create(&main->philo[i].thread, NULL, &life,
				(void *)main) != 0)
			return (1);
		i++;
		usleep(1000);
	}
	if (pthread_create(&main->monitor, NULL, &check_it, (void *)main) != 0)
		return (1);
	usleep(1000);
	if (join_threads(main))
		return (1);
	return (0);
}

int	destroy_threads(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->input.nb_philo)
	{
		pthread_mutex_destroy(&main->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&main->write);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <ilyanamegy@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:22:26 by ilymegy           #+#    #+#             */
/*   Updated: 2023/12/07 21:28:40 by ilymegy          ###   ########.fr       */
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
	return (0);
}

int	init_mutexs(t_main *main)
{
	if (pthread_mutex_init(&main->write, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&main->n_thr, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&main->philo_died, NULL) != 0)
		return (1);
	return (0);
}

int	init_threads(t_main *main)
{
	int	i;

	main->philo_dead = 0;
	main->t0 = get_time();
	if (init_mutexs(main))
		return (1);
	i = 0;
	while (i < main->input.nb_philo)
	{
		pthread_mutex_lock(&main->n_thr);
		main->n_thread = i;
		pthread_mutex_unlock(&main->n_thr);
		if (pthread_create(&main->philo[i].thread, NULL, &life,
				(void *)main) != 0)
			return (1);
		i++;
		usleep(100);
	}
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

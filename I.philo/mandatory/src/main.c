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

int	alone_philo(t_main *main)
{
	long long	now;

	if (pthread_mutex_init(&main->write, NULL) != 0)
		return (1);
	main->t0 = get_time();
	now = diff_time(main->t0);
	pthread_mutex_lock(&main->write);
	printf("%s%-10lld %-3d %-30s%s\n", main->c.cyan, now, 1, main->a.fork,
		main->c.reset);
	pthread_mutex_unlock(&main->write);
	usleep(1000 * main->input.ttd);
	now = diff_time(main->t0);
	pthread_mutex_lock(&main->write);
	printf("%s%-10lld %-3d %-30s%s\n", main->c.red, now, 1,
		"died sad and alone", main->c.reset);
	pthread_mutex_unlock(&main->write);
	return (0);
}

int	main(int ac, char **av)
{
	t_main	main;

	if (check_args(ac, av, &main))
		return (1);
	if (init_philos(&main))
		return (1);
	if (init_forks(&main))
		return (free(main.philo), 1);
	if (main.input.nb_philo == 1)
	{
		if (alone_philo(&main))
			return (philo_free(&main), 1);
		return (philo_free(&main), 0);
	}
	if (init_threads(&main))
		return (philo_free(&main), 1);
	if (destroy_threads(&main))
		return (philo_free(&main), 1);
	philo_free(&main);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:44:29 by ilymegy           #+#    #+#             */
/*   Updated: 2023/11/19 13:44:30 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int	philo_words(t_main *main, int id, char *color, char *s)
{
	long long	now;

	now = diff_time(main->t0);
	if (main->philo_dead)
		return (1);
	pthread_mutex_lock(&main->write);
	if (main->philo_dead)
	{
		pthread_mutex_unlock(&main->write);
		return (1);
	}
	else
		printf("%s%-10lld %-3d %-30s%s\n", color, now, id, s, main->c.reset);
	pthread_mutex_unlock(&main->write);
	return (0);
}

void	*life(void *arg)
{
	t_main	*main;
	int		i;

	main = (t_main *)arg;
	i = main->n_thread;
	if (main->input.nb_of_times_eat > 0)
	{
		while (main->input.nb_of_times_eat > main->philo[i].nb_of_times_ate
			&& main->philo_dead == 0)
			do_life(main, i);
	}
	else
	{
		while (main->philo_dead == 0)
			if (do_life(main, i))
				break ;
	}
	return (0);
}

int	do_life(t_main *main, int i)
{
	
}

void	*check_it(void *arg)
{
}
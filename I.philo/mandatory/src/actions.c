/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <ilyanamegy@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:40:05 by ilymegy           #+#    #+#             */
/*   Updated: 2023/12/18 00:45:42 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int	drop_forks(t_main *main, int i)
{
	if (main->philo[i].id % 2 == 0)
	{
		if (pthread_mutex_unlock(&main->forks[main->philo[i].fork.right]))
			return (0);
		if (pthread_mutex_unlock(&main->forks[main->philo[i].fork.left]))
			return (0);
	}
	else
	{
		if (pthread_mutex_unlock(&main->forks[main->philo[i].fork.left]))
			return (0);
		if (pthread_mutex_unlock(&main->forks[main->philo[i].fork.right]))
			return (0);
	}
	pthread_mutex_lock(&main->philo_ate[i]);
	main->philo[i].nb_of_times_ate++;
	pthread_mutex_unlock(&main->philo_ate[i]);
	return (1);
}

void	left_or_right_fork(t_main *main, int i, pthread_mutex_t **first,
		pthread_mutex_t **sec)
{
	if (main->philo[i].id % 2 == 0)
	{
		*first = &main->forks[main->philo[i].fork.right];
		*sec = &main->forks[main->philo[i].fork.left];
	}
	else
	{
		*first = &main->forks[main->philo[i].fork.left];
		*sec = &main->forks[main->philo[i].fork.right];
	}
}

int	someone_dead(t_main *main, pthread_mutex_t *fork)
{
	pthread_mutex_lock(&main->philo_died);
	if (main->philo_dead)
	{
		pthread_mutex_unlock(&main->philo_died);
		pthread_mutex_unlock(fork);
		return (1);
	}
	pthread_mutex_unlock(&main->philo_died);
	return (0);
}

int	do_eat(t_main *main, int i)
{
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*sec_fork;

	left_or_right_fork(main, i, &first_fork, &sec_fork);
	pthread_mutex_lock(first_fork);
	if (someone_dead(main, first_fork))
		return (0);
	if (!philo_words(main, main->philo[i].id, main->a.fork))
		return (pthread_mutex_unlock(first_fork), 0);
	pthread_mutex_lock(sec_fork);
	if (someone_dead(main, first_fork))
		return (pthread_mutex_unlock(sec_fork), 0);
	if (!philo_words(main, main->philo[i].id, main->a.fork))
		return (drop_forks(main, i), 0);
	if (!philo_words(main, main->philo[i].id, main->a.eat))
		return (drop_forks(main, i), 0);
	pthread_mutex_lock(&main->philo_ttd[i]);
	main->philo[i].ttd = get_time();
	pthread_mutex_unlock(&main->philo_ttd[i]);
	if (die_before_end(main, i, main->input.tte, 0))
		return (drop_forks(main, i), 0);
	drop_forks(main, i);
	return (1);
}

int	philo_words(t_main *main, int id, char *s)
{
	long long	now;

	now = diff_time(main->t0);
	pthread_mutex_lock(&main->philo_died);
	pthread_mutex_lock(&main->write);
	if (main->philo_dead)
	{
		pthread_mutex_unlock(&main->philo_died);
		pthread_mutex_unlock(&main->write);
		return (0);
	}
	printf("%lld %d %s\n", now, id, s);
	pthread_mutex_unlock(&main->write);
	pthread_mutex_unlock(&main->philo_died);
	return (1);
}

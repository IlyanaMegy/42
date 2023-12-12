/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <ilyanamegy@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:40:05 by ilymegy           #+#    #+#             */
/*   Updated: 2023/12/09 21:51:06 by ilymegy          ###   ########.fr       */
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
	if (pthread_mutex_lock(first_fork) != 0)
		return (0);
	if (someone_dead(main, first_fork))
		return (0);
	if (!philo_words(main, main->philo[i].id, main->c.cyan, main->a.fork))
		return (0);
	if (pthread_mutex_lock(sec_fork) != 0)
		return (0);
	if (someone_dead(main, first_fork))
		return (pthread_mutex_unlock(sec_fork), 0);
	if (!philo_words(main, main->philo[i].id, main->c.cyan, main->a.fork))
		return (0);
	if (!philo_words(main, main->philo[i].id, main->c.blue, main->a.eat))
		return (0);
	pthread_mutex_lock(&main->philo_ttd[i]);
	main->philo[i].ttd = get_time();
	pthread_mutex_unlock(&main->philo_ttd[i]);
	if (die_before_end(main, i, main->input.tte, 0))
		return (drop_forks(main, i), 0);
	drop_forks(main, i);
	return (1);
}

int	philo_words(t_main *main, int id, char *color, char *s)
{
	long long	now;

	now = diff_time(main->t0);
	pthread_mutex_lock(&main->philo_died);
	if (main->philo_dead)
		return (pthread_mutex_unlock(&main->philo_died), 0);
	pthread_mutex_lock(&main->write);
	if (main->philo_dead)
	{
		pthread_mutex_unlock(&main->philo_died);
		pthread_mutex_unlock(&main->write);
		return (0);
	}
	pthread_mutex_unlock(&main->philo_died);
	if (*color)
		printf("%lld %d %s\n", now, id, s);
	// printf("%s%-10lld %-3d %-30s%s\n", color, now, id, s, main->c.reset);
	pthread_mutex_unlock(&main->write);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:16:34 by ilymegy           #+#    #+#             */
/*   Updated: 2023/12/07 17:16:36 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	lock_unlock_it(pthread_mutex_t *fst, pthread_mutex_t *sec, int state)
{
	if (!state)
	{
		pthread_mutex_lock(fst);
		pthread_mutex_lock(sec);
		return ;
	}
	pthread_mutex_unlock(fst);
	pthread_mutex_unlock(sec);
	return ;
}

void	check_no_lim_eat(t_main *main, int i)
{
	lock_unlock_it(&main->philo_ate[i], &main->philo_died, 0);
	while (!main->philo_dead)
	{
		lock_unlock_it(&main->philo_ate[i], &main->philo_died, 1);
		if (is_dead(main, &i))
		{
			lock_unlock_it(&main->philo_ate[i], &main->philo_died, 0);
			break ;
		}
		lock_unlock_it(&main->philo_ate[i], &main->philo_died, 0);
	}
	lock_unlock_it(&main->philo_ate[i], &main->philo_died, 1);
}

void	*check_it(void *arg)
{
	t_main	*main;
	int		i;

	main = (t_main *)arg;
	i = 0;
	if (main->input.nb_of_times_eat > 0)
	{
		lock_unlock_it(&main->philo_ate[i], &main->philo_died, 0);
		while (main->input.nb_of_times_eat > main->philo[i].nb_of_times_ate
			&& !main->philo_dead)
		{
			lock_unlock_it(&main->philo_ate[i], &main->philo_died, 1);
			if (is_dead(main, &i))
			{
				lock_unlock_it(&main->philo_ate[i], &main->philo_died, 0);
				break ;
			}
			lock_unlock_it(&main->philo_ate[i], &main->philo_died, 0);
		}
		lock_unlock_it(&main->philo_ate[i], &main->philo_died, 1);
	}
	else
		check_no_lim_eat(main, i);
	return (NULL);
}

int	is_dead(t_main *main, int *i)
{
	int	t;

	if (*i == main->input.nb_philo)
		*i = 0;
	pthread_mutex_lock(&main->philo_ttd[*i]);
	t = diff_time(main->philo[*i].ttd);
	pthread_mutex_unlock(&main->philo_ttd[*i]);
	if (t > main->input.ttd)
	{
		philo_words(main, main->philo[*i].id, main->c.red, main->a.die);
		pthread_mutex_lock(&main->philo_died);
		main->philo_dead = 1;
		pthread_mutex_unlock(&main->philo_died);
		return (1);
	}
	i++;
	return (0);
}

void	die_before_end(t_main *main, int i, int action, int option)
{
	if (get_time() + action > main->philo[i].ttd)
	{
		usleep(1000 * (main->input.ttd - option));
		philo_words(main, main->philo[i].id, main->c.red, main->a.die);
		pthread_mutex_lock(&main->philo_died);
		main->philo_dead = 1;
		pthread_mutex_unlock(&main->philo_died);
	}
	else
		usleep(action * 1000);
}

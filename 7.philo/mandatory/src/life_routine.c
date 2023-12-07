/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_routine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <ilyanamegy@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:44:29 by ilymegy           #+#    #+#             */
/*   Updated: 2023/12/07 21:49:31 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	life_no_lim_eat(t_main *main, int i)
{
	pthread_mutex_lock(&main->philo_died);
	while (!main->philo_dead)
	{
		pthread_mutex_unlock(&main->philo_died);
		if (!do_life(main, i))
		{
			pthread_mutex_lock(&main->philo_died);
			break ;
		}
		pthread_mutex_lock(&main->philo_died);
	}
	pthread_mutex_unlock(&main->philo_died);
}

void	*life(void *arg)
{
	t_main	*main;
	int		i;

	main = (t_main *)arg;
	pthread_mutex_lock(&main->n_thr);
	i = main->n_thread;
	pthread_mutex_unlock(&main->n_thr);
	if (main->philo[i].id % 2 == 0)
		ft_usleep(main->input.tte / 10);
	if (main->input.nb_of_times_eat > 0)
	{
		pthread_mutex_lock(&main->philo_died);
		while (main->input.nb_of_times_eat > main->philo[i].nb_of_times_ate
			&& !main->philo_dead)
		{
			pthread_mutex_unlock(&main->philo_died);
			do_life(main, i);
			pthread_mutex_lock(&main->philo_died);
		}
		pthread_mutex_unlock(&main->philo_died);
	}
	else
		life_no_lim_eat(main, i);
	return (NULL);
}

int	do_life(t_main *main, int i)
{
	if (!do_eat(main, i))
		return (0);
	if (main->input.nb_of_times_eat != main->philo[i].nb_of_times_ate)
	{
		if (!philo_words(main, main->philo[i].id, main->c.purple,
				main->a.sleep))
			return (0);
		do_action(main->input.tts);
		if (!philo_words(main, main->philo[i].id, main->c.pink, main->a.think))
			return (0);
	}
	return (1);
}

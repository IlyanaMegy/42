/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_routine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <ilyanamegy@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:44:29 by ilymegy           #+#    #+#             */
/*   Updated: 2023/12/09 21:47:42 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	life_no_lim_eat(t_main *main, int i)
{
	pthread_mutex_lock(&main->philo_died);
	while (!main->philo_dead)
	{
		pthread_mutex_unlock(&main->philo_died);
		if (is_dead(main, i))
			return ;
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
	if (main->input.nb_of_times_eat > 0)
	{
		pthread_mutex_lock(&main->philo_died);
		while (main->input.nb_of_times_eat != main->philo[i].nb_of_times_ate
			&& !main->philo_dead)
		{
			pthread_mutex_unlock(&main->philo_died);
			if (is_dead(main, i))
				return (NULL);
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
	if (is_dead(main, i))
		return (0);
	if (!do_eat(main, i))
		return (0);
	if (main->input.nb_of_times_eat != main->philo[i].nb_of_times_ate)
	{
		if (is_dead(main, i))
			return (0);
		if (!philo_words(main, main->philo[i].id, main->a.sleep))
			return (0);
		if (die_before_end(main, i, main->input.tts, main->input.tte))
			return (0);
		if (is_dead(main, i))
			return (0);
		if (!philo_words(main, main->philo[i].id, main->a.think))
			return (0);
		if (die_before_end(main, i, main->input.ttt, main->input.tte
				+ main->input.tts))
			return (0);
	}
	return (1);
}

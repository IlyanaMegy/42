/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <ilyanamegy@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:16:34 by ilymegy           #+#    #+#             */
/*   Updated: 2023/12/09 21:48:09 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int	is_dead(t_main *main, int i)
{
	int	t;

	pthread_mutex_lock(&main->philo_ttd[i]);
	t = diff_time(main->philo[i].ttd);
	pthread_mutex_unlock(&main->philo_ttd[i]);
	if (t > main->input.ttd)
	{
		philo_words(main, main->philo[i].id, main->a.die);
		pthread_mutex_lock(&main->philo_died);
		main->philo_dead = 1;
		pthread_mutex_unlock(&main->philo_died);
		return (1);
	}
	return (0);
}

int	die_before_end(t_main *main, int i, int action, int option)
{
	if (get_time() + action > get_time() + main->input.ttd - option)
	{
		if (ft_usleep(main, main->input.ttd - option))
			return (1);
		if (!philo_words(main, main->philo[i].id, main->a.die))
			return (1);
		pthread_mutex_lock(&main->philo_died);
		main->philo_dead = 1;
		pthread_mutex_unlock(&main->philo_died);
		return (1);
	}
	if (ft_usleep(main, action))
		return (1);
	return (0);
}

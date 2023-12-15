/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <ilyanamegy@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:25:22 by ilymegy           #+#    #+#             */
/*   Updated: 2023/12/07 21:48:16 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec * 0.001));
}

long long	diff_time(long long t)
{
	if (t > 0)
		return (get_time() - t);
	return (0);
}

int	ft_usleep(t_main *main, int time_action)
{
	while (time_action >= 5)
	{
		pthread_mutex_lock(&main->philo_died);
		if (main->philo_dead)
			return (pthread_mutex_unlock(&main->philo_died), 1);
		pthread_mutex_unlock(&main->philo_died);
		usleep(5000);
		time_action -= 5;
	}
	if (time_action)
	{
		pthread_mutex_lock(&main->philo_died);
		if (main->philo_dead)
			return (pthread_mutex_unlock(&main->philo_died), 1);
		pthread_mutex_unlock(&main->philo_died);
		usleep(time_action * 1000);
	}
	return (0);
}

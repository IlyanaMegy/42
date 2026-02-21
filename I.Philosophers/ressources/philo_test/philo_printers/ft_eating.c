/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eating.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:13:05 by apayet            #+#    #+#             */
/*   Updated: 2022/08/04 10:41:15 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_eating(void *element)
{
	t_philo		*philo;
	t_timestamp	eating;

	philo = (t_philo *)element;
	pthread_mutex_lock(ft_get_m_writer());
	if (is_one_philo_has_died())
	{
		pthread_mutex_unlock(ft_get_m_writer());
		return ;
	}
	eating = ft_get_timestamp();
	philo->last_launch_time = eating;
	philo->next_death_time = ft_add_timestamp(eating, ft_get_pace_die());
	printf("%ld %d is eating\n", eating.msec, philo->id);
	philo->nbr_of_eat += 1;
	pthread_mutex_unlock(ft_get_m_writer());
}

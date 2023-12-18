/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_taking_fork.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:12:16 by apayet            #+#    #+#             */
/*   Updated: 2022/08/04 10:42:00 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_taking_fork(void *element)
{
	t_philo			*philo;

	philo = (t_philo *)element;
	pthread_mutex_lock(ft_get_m_writer());
	if (is_one_philo_has_died())
	{
		pthread_mutex_unlock(ft_get_m_writer());
		return ;
	}
	printf("%ld %d has taken a fork\n", ft_get_timestamp().msec, philo->id);
	pthread_mutex_unlock(ft_get_m_writer());
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_mutex_death.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:38:07 by apayet            #+#    #+#             */
/*   Updated: 2022/07/28 13:42:18 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/**
 * @brief 
 * 
 */
int	ft_create_mutex_death(void)
{
	t_data	*data;

	data = ft_get_data_addr((t_data *)0);
	data->m_death = ft_malloc(data, sizeof(pthread_mutex_t), 1);
	if (ft_get_data_addr((t_data *)0)->m_death == (pthread_mutex_t *)0)
		return (0);
	pthread_mutex_init(ft_get_data_addr((t_data *)0)->m_death, NULL);
	return (1);
}

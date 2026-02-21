/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_mutex_lock_check.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:38:57 by apayet            #+#    #+#             */
/*   Updated: 2022/07/28 13:43:52 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/**
 * @brief 
 * 
 */
int	ft_create_mutex_lock_check(void)
{
	t_data	*data;

	data = ft_get_data_addr((t_data *)0);
	data->m_lock_check = ft_malloc(data, sizeof(pthread_mutex_t), 1);
	if (ft_get_data_addr((t_data *)0)->m_lock_check == (pthread_mutex_t *)0)
		return (0);
	pthread_mutex_init(ft_get_data_addr((t_data *)0)->m_lock_check, NULL);
	return (1);
}

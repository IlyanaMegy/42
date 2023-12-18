/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_mutex_printer.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:41:36 by apayet            #+#    #+#             */
/*   Updated: 2022/07/28 13:44:22 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_create_mutex_printer(void)
{
	t_data	*data;

	data = ft_get_data_addr((t_data *)0);
	data->m_writer = ft_malloc(data, sizeof(pthread_mutex_t), 1);
	if (ft_get_data_addr((t_data *)0)->m_writer == (pthread_mutex_t *)0)
		return (0);
	pthread_mutex_init(ft_get_m_writer(), NULL);
	return (1);
}

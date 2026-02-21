/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_mutex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 11:26:10 by apayet            #+#    #+#             */
/*   Updated: 2022/07/21 15:02:36 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/**
 * @brief Get the mutex of the forks with the id value
 * 			this is a access shortcut
 * @param id 
 * @return pthread_mutex_t* 
 */
pthread_mutex_t	*ft_get_mutex(int id)
{
	return (&(ft_get_data_addr((t_data *)0)->forks[id].mutex));
}

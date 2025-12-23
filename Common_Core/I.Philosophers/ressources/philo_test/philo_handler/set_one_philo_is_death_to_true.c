/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_one_philo_is_death_to_true.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:52:06 by apayet            #+#    #+#             */
/*   Updated: 2022/07/27 17:53:15 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/**
 * @brief Set one philo_to_death
 * 
 * @param data 
 */
void	set_one_philo_is_death_to_true(t_data *data)
{
	pthread_mutex_lock(ft_get_m_death());
	data->one_philo_is_dead = 1;
	pthread_mutex_unlock(ft_get_m_death());
}

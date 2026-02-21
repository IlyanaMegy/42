/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_one_philo_has_died.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:19:18 by apayet            #+#    #+#             */
/*   Updated: 2022/07/25 17:19:46 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/**
 * @brief This function is called before printing an action and it is a bypass 
 * 
 * @return int return true if one philo is dead else return 0
 */
int	is_one_philo_has_died(void)
{
	t_data	*data;

	data = ft_get_data_addr((t_data *)0);
	pthread_mutex_lock(ft_get_m_death());
	if (data->one_philo_is_dead == 1)
	{
		pthread_mutex_unlock(ft_get_m_death());
		return (1);
	}
	else
		pthread_mutex_unlock(ft_get_m_death());
	return (0);
}

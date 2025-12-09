/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_estimated_thinking_time.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:08:24 by apayet            #+#    #+#             */
/*   Updated: 2022/08/02 19:39:47 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/**
 * @brief The time to think is estimated with theses conditions
 * 
 */
void	ft_set_estimated_thinking_time(void)
{
	long int	res;
	t_data		*data;

	res = 0;
	data = ft_get_data_addr((void *)0);
	if (ft_get_pace_sleep() < ft_get_pace_eat())
	{
		res = ft_get_pace_eat() - ft_get_pace_sleep();
		if ((ft_get_pace_eat() + ft_get_pace_sleep() + res) > ft_get_pace_die())
		{
			res = ft_get_pace_die();
			res = res - (ft_get_pace_eat() + ft_get_pace_sleep());
			if (res < 0)
				res = 0;
		}
	}
	data->est_time_to_think = res;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_launch_timestamp.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:13:46 by apayet            #+#    #+#             */
/*   Updated: 2022/07/27 17:18:34 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/**
 * @brief Set the launch timestamp object 
 * 			It is called after the eating and before the sleeping
 * @param philo 
 */
void	set_launch_timestamp(t_philo *philo)
{
	u_int64_t			added_time;
	struct s_timestamp	(*add)(t_timestamp, u_int64_t);

	add = &ft_add_timestamp;
	added_time = ft_get_pace_die() / TIME_COEF;
	philo->last_launch_time = ft_get_timestamp();
	philo->next_death_time = add(philo->last_launch_time, added_time);
}

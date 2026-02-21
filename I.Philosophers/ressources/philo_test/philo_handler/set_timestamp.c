/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_timestamp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:58:52 by apayet            #+#    #+#             */
/*   Updated: 2022/08/02 19:04:27 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	set_timestamp(t_philo *phil, t_timestamp *ref, t_timestamp base)
{
	struct s_timestamp	(*add)(t_timestamp, u_int64_t);

	add = &ft_add_timestamp;
	ref[ACTION_EAT] = add(base, ft_get_pace_eat() / TIME_COEF);
	ref[ACTION_SLEEP] = add(base, ft_get_pace_sleep() / TIME_COEF);
	ref[ACTION_THINK] = add(base, ft_get_pace_est_think() / TIME_COEF);
	ref[ACTION_DEATH_TIME] = phil->next_death_time;
}

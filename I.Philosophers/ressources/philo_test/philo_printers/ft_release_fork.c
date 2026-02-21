/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_release_fork.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:26:07 by apayet            #+#    #+#             */
/*   Updated: 2022/08/04 09:08:04 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_hold_mutex(t_fork *hand)
{
	pthread_mutex_t	*hand_mutex;

	hand_mutex = ft_get_mutex(hand->id);
	pthread_mutex_lock(hand_mutex);
}

void	ft_release_mutex(t_fork *hand)
{
	pthread_mutex_t	*hand_mutex;

	hand_mutex = ft_get_mutex(hand->id);
	pthread_mutex_unlock(hand_mutex);
}

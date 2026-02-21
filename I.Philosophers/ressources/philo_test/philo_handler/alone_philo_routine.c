/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alone_philo_routine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:21:52 by apayet            #+#    #+#             */
/*   Updated: 2022/07/25 19:22:16 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/**
 * @brief This function is a spoecial routine when the philo nbr is eq to 1,
 *  no fork for earting so just wait until the philo is dead
 * 
 * @param element 
 * @return void* 
 */
void	*alone_philo_routine(void *element)
{
	t_philo	*philo;

	philo = (t_philo *)element;
	ft_hold_mutex(philo->right_hand);
	ft_taking_fork(element);
	usleep(ft_get_pace_die());
	ft_is_died(philo);
	ft_release_mutex(philo->right_hand);
	return ((void *)0);
}

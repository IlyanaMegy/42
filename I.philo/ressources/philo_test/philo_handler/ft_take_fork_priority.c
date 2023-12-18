/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_fork_priority.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:17:12 by apayet            #+#    #+#             */
/*   Updated: 2022/08/04 09:50:54 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	normal_taking_fork_priority(void *element, t_philo *philo)
{
	ft_hold_mutex(philo->left_hand);
	philo->left_fork_taken = 1;
	ft_taking_fork(element);
	if (is_one_philo_has_died() == 1)
		return ;
	ft_hold_mutex(philo->right_hand);
	philo->right_fork_taken = 1;
	ft_taking_fork(element);
}

static void	last_philo_taking_fork_priority(void *element, t_philo *philo)
{
	ft_hold_mutex(philo->right_hand);
	philo->right_fork_taken = 1;
	ft_taking_fork(element);
	if (is_one_philo_has_died() == 1)
		return ;
	ft_hold_mutex(philo->left_hand);
	philo->left_fork_taken = 1;
	ft_taking_fork(element);
}

/**
 * @brief This function will lock mutex in the right order
 * 			The last philo must have inverted order
 * 
 * @param element 
 * @param philo 
 */
void	ft_take_fork_priority(void *element, t_philo *philo)
{
	if (philo->id == ft_get_data_addr((t_data *)0)->nbr_of_philo)
		last_philo_taking_fork_priority(element, philo);
	else
		normal_taking_fork_priority(element, philo);
}

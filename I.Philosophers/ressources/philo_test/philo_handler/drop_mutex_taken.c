/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drop_mutex_taken.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:18:44 by apayet            #+#    #+#             */
/*   Updated: 2022/07/25 19:19:13 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	drop_mutex_taken(t_philo *philo)
{
	if (philo->left_fork_taken == 1 && philo->right_fork_taken == 1)
	{
		ft_release_mutex(philo->right_hand);
		ft_release_mutex(philo->left_hand);
		philo->left_fork_taken = 0;
		philo->right_fork_taken = 0;
	}
	else if (philo->left_fork_taken == 1 && philo->right_fork_taken == 0)
	{
		ft_release_mutex(philo->left_hand);
		philo->left_fork_taken = 0;
	}
	else if (philo->left_fork_taken == 0 && philo->right_fork_taken == 1)
	{
		ft_release_mutex(philo->right_hand);
		philo->right_fork_taken = 0;
	}
}

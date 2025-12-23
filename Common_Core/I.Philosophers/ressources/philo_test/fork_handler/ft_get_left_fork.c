/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_left_fork.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:40:19 by apayet            #+#    #+#             */
/*   Updated: 2022/07/21 16:19:23 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/**
 * @brief This function assign the rigth fork for the right philo 
 * 			This is not the action of taking a fork asked inside the subject
 * 
 * @param philo_id 
 * @return t_fork* 
 */
t_fork	*ft_get_left_fork(int philo_id)
{
	int	(*get_id)(int);

	get_id = &ft_get_idleft_from_philo;
	return (&(ft_get_data_addr((t_data *)0)->forks[get_id(philo_id)]));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_right_fork.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:42:26 by apayet            #+#    #+#             */
/*   Updated: 2022/07/21 16:19:42 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/**
 * @brief  	This function assign the rigth fork for the right philo 
 * 			This is not the action of taking a fork asked inside the subject
 * 
 * @param id_philo 
 * @return t_fork* 
 */
t_fork	*ft_get_right_fork(int id_philo)
{
	int	(*get_id)(int);

	get_id = &ft_get_idright_from_philo;
	return (&(ft_get_data_addr((t_data *)0)->forks[get_id(id_philo)]));
}

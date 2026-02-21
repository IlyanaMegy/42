/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_end_of_dinner.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:11:44 by apayet            #+#    #+#             */
/*   Updated: 2022/07/25 19:12:27 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/**
 * @brief This function check how many dinner each philo have done
 * 
 * @param philo 
 * @return int The return value is 1 when all philo has done the nbr of eating
 */
int	is_end_of_dinner(t_philo *philo)
{
	t_data	*(*get)(t_data *);

	get = &ft_get_data_addr;
	if (philo->nbr_of_eat == get((t_data *)0)->pace.nbr_each_must_eat)
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:41:46 by apayet            #+#    #+#             */
/*   Updated: 2022/07/12 17:21:04 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/**
 * @brief This is the parser of the program, it set all args
 * 
 */
void	ft_parser(void)
{
	if (ft_get_ac() == 6)
	{
		ft_get_data_addr((t_data *)0)->flag.count_nbr_must_eat_activated = 1;
		ft_get_data_addr((t_data *)0)->pace.nbr_each_must_eat = \
		ft_atoi(ft_get_av()[NBR_OF_EAT]);
	}
	ft_get_data_addr((t_data *)0)->nbr_of_philo = \
	ft_atoi(ft_get_av()[NBR_PHILO]);
	ft_get_data_addr((t_data *)0)->pace.time_to_die = \
	ft_atoi(ft_get_av()[DEAD_TIME]);
	ft_get_data_addr((t_data *)0)->pace.time_to_eat = \
	ft_atoi(ft_get_av()[EAT_TIME]);
	ft_get_data_addr((t_data *)0)->pace.time_to_sleep = \
	ft_atoi(ft_get_av()[SLEEP_TIME]);
}

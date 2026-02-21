/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_philo_dead_instant.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 21:50:31 by apayet            #+#    #+#             */
/*   Updated: 2022/08/01 21:51:17 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	all_philo_dead_instant(void)
{
	t_data	*data;
	int		i;

	i = 1;
	data = ft_get_data_addr((t_data *)0);
	while (i <= data->nbr_of_philo)
	{
		printf("%ld %d died\n", data->program_started.msec, i);
		i++;
	}
	return ;
}

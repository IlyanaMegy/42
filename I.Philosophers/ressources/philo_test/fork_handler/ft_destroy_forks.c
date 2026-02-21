/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_forks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 11:15:10 by apayet            #+#    #+#             */
/*   Updated: 2022/07/21 15:02:10 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_destroy_forks(void)
{
	int	i;

	i = 0;
	while (i < ft_get_data_addr((t_data *)0)->nbr_of_philo)
	{
		pthread_mutex_destroy(ft_get_mutex(i));
		i++;
	}
}

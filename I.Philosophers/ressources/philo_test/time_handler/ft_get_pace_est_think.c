/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pace_est_think.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:50:13 by apayet            #+#    #+#             */
/*   Updated: 2022/08/02 19:01:13 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long int	ft_get_pace_est_think(void)
{
	t_data	*data;

	data = (t_data *)ft_get_data_addr((void *)0);
	return (data->est_time_to_think);
}

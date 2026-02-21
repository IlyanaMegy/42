/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_timestamp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:49:34 by apayet            #+#    #+#             */
/*   Updated: 2022/07/21 15:10:41 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_timestamp	ft_get_timestamp(void)
{
	struct timeval	now;
	int				status;
	t_timestamp		res;

	res.usec = 0;
	res.msec = 0;
	status = 0;
	status = gettimeofday(&now, NULL);
	if (status < 0)
	{
		printf("Error \ngettimeoftheday error \n");
		return (res);
	}
	res.usec = (u_int64_t)((now.tv_sec * 1000000) + now.tv_usec);
	res.msec = (u_int64_t)(res.usec / 1000);
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <ilyanamegy@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:25:22 by ilymegy           #+#    #+#             */
/*   Updated: 2023/12/07 21:48:16 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec * 0.001));
}

long long	diff_time(long long t)
{
	if (t > 0)
		return (get_time() - t);
	return (0);
}

void	ft_usleep(long int ms)
{
	long int	start_time;

	start_time = get_time();
	while ((get_time() - start_time) < ms)
		usleep(ms / 10);
}

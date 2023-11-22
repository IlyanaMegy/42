/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 11:18:13 by ilymegy           #+#    #+#             */
/*   Updated: 2023/11/18 11:18:17 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	exit_handler(char *msg)
{
	printf("%s", msg);
	exit(0);
}

int	p_atoi(char *str)
{
	long int	n;
	int			i;

	i = 0;
	n = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + str[i] - '0';
		i++;
	}
	if (n < 0 || ((str[i] < '0' || str[i] > '9') && str[i] != '\0')
		|| n > 2147483647)
		return (0);
	return (n);
}

void	philo_free(t_main *main)
{
	free(main->philo);
	free(main->forks);
}

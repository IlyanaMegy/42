/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_forks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:05:53 by ilymegy           #+#    #+#             */
/*   Updated: 2023/11/18 19:05:56 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int	init_forks(t_main *main)
{
	int	i;

	main->forks = malloc(sizeof(pthread_mutex_t) * main->input.nb_philo + 1);
	if (main->forks == NULL)
		return (1);
	i = 0;
	while (i < main->input.nb_philo)
	{
		if (pthread_mutex_init(&main->forks[i], NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}

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

	main->forks = malloc(sizeof(pthread_mutex_t) * main->input.nb_philo);
	main->philo_ttd = malloc(sizeof(pthread_mutex_t) * main->input.nb_philo);
	main->philo_ate = malloc(sizeof(pthread_mutex_t) * main->input.nb_philo);
	if (!main->forks || !main->philo_ttd || !main->philo_ate)
		return (1);
	i = 0;
	while (i < main->input.nb_philo)
	{
		if (pthread_mutex_init(&main->forks[i], NULL) != 0)
			return (free(main->forks), 1);
		if (pthread_mutex_init(&main->philo_ttd[i], NULL) != 0)
			return (free(main->forks), free(main->philo_ttd), 1);
		if (pthread_mutex_init(&main->philo_ate[i], NULL) != 0)
			return (free(main->forks), free(main->philo_ttd), 1);
		i++;
	}
	return (0);
}

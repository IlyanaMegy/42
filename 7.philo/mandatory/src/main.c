/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 11:15:12 by ilymegy           #+#    #+#             */
/*   Updated: 2023/11/18 11:15:17 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int	alone_philo(t_main *main)
{
	if (pthread_mutex_init(&main->write, NULL) != 0)
		return (1);
	main->t0 = get_time();
	philo_words(main, 1, main->c.cyan, main->a.fork);
	do_action(main->input.ttd);
	philo_words(main, 1, main->c.red, "died sad and alone");
	return (0);
}

int	main(int ac, char **av)
{
	t_main	main;

	if (check_args(ac, av, &main))
		return (1);
	if (init_philos(&main))
		return (1);
	if (init_forks(&main))
		return (free(main.philo), 1);
	if (main.input.nb_philo == 1)
	{
		if (alone_philo(&main))
			return (philo_free(&main), 1);
		return (philo_free(&main), 0);
	}
	return (0);
}

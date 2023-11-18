/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 11:15:24 by ilymegy           #+#    #+#             */
/*   Updated: 2023/11/18 11:15:28 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int	init_struct(int ac, char **av, t_main *main)
{
	if (ac == 5 || ac == 6)
	{
		main->input.num_philo = p_atoi(av[1]);
		main->input.time_to_die = p_atoi(av[2]);
		main->input.time_to_eat = p_atoi(av[3]);
		main->input.time_to_sleep = p_atoi(av[4]);
		if (ac == 6)
			main->input.num_of_times_eat = p_atoi(av[5]);
		else
			main->input.num_of_times_eat = -1;
		return (0);
	}
	return (1);
}

void	print_args_errors(int ac, t_main *main)
{
	if (!main->input.num_philo)
		printf("__ERROR_ARG__: No philosopher here.\n");
	if (!main->input.time_to_die)
		printf("__ERROR_ARG__: Time to die is null.\n");
	if (!main->input.time_to_eat)
		printf("__ERROR_ARG__: Time to eat is null.\n");
	if (!main->input.time_to_sleep)
		printf("__ERROR_ARG__: Time to sleep is null.\n");
	if (ac == 6 && !main->input.num_of_times_eat)
		printf("__ERROR_ARG__: Philosophers need to eat at least 1 time.\n");
}

int	check_args(int ac, char **av, t_main *main)
{
	if (init_struct(ac, av, main))
	{
		printf("__ERROR_ARGS__: Invalid number of args.\n");
		return (1);
	}
	else
	{
		print_args_errors(ac, main);
		if (!main->input.num_philo || !main->input.time_to_die
			|| !main->input.time_to_eat || !main->input.time_to_sleep
			|| (ac == 6 && !main->input.num_of_times_eat))
			return (1);
	}
	return (0);
}

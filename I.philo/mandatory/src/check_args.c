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
		main->input.nb_philo = p_atoi(av[1]);
		main->input.ttd = p_atoi(av[2]);
		main->input.tte = p_atoi(av[3]);
		main->input.tts = p_atoi(av[4]);
		if (ac == 6)
			main->input.nb_of_times_eat = p_atoi(av[5]);
		else
			main->input.nb_of_times_eat = -1;
		return (0);
	}
	return (1);
}

void	print_args_errors(int ac, t_main *main)
{
	if (!main->input.nb_philo)
		printf("%s%s%s\n", main->c.red, main->err.arg1, main->c.reset);
	if (!main->input.ttd)
		printf("%s%s%s\n", main->c.red, main->err.arg2, main->c.reset);
	if (!main->input.tte)
		printf("%s%s%s\n", main->c.red, main->err.arg3, main->c.reset);
	if (!main->input.tts)
		printf("%s%s%s\n", main->c.red, main->err.arg4, main->c.reset);
	if (ac == 6 && !main->input.nb_of_times_eat)
		printf("%s%s%s\n", main->c.red, main->err.arg5, main->c.reset);
}

int	check_args(int ac, char **av, t_main *main)
{
	set_msg_and_colors(main);
	if (init_struct(ac, av, main))
	{
		printf("%s%s%s\n", main->c.red, main->err.nb_args, main->c.reset);
		return (1);
	}
	else
	{
		print_args_errors(ac, main);
		if (!main->input.nb_philo || !main->input.ttd || !main->input.tte
			|| !main->input.tts || (ac == 6 && !main->input.nb_of_times_eat))
			return (1);
	}
	return (0);
}
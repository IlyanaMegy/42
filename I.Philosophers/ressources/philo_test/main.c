/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:28:26 by apayet            #+#    #+#             */
/*   Updated: 2022/08/02 18:55:33 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Initialize the program and set struct and args
 * 
 * @param data 
 * @param ac 
 * @param av 
 * @param envp 
 * 
 * @return int return 1 if need to stop
 * 				return 0 if everything is okay
 */
static int	init_data(t_data *data, int ac, char **av, char **envp)
{
	ft_get_data_addr(data);
	ft_init_struct();
	ft_set_args(ac, av, envp);
	if (ft_check_args() == 0)
		return (1);
	return (0);
}

/**
 * @brief This function is called just before the create_thread
 * 			 of the philosohers process
 * return 0 if it fails and return 1 if okay
 */
static int	prepare_program(t_data *data)
{
	ft_parser();
	data->program_started = ft_get_timestamp();
	if (data->nbr_of_philo == 0)
		return (0);
	ft_set_estimated_thinking_time();
	if (data->pace.time_to_die == 0)
	{
		all_philo_dead_instant();
		return (0);
	}
	if (ft_populate_philo() == 0)
		return (0);
	if (ft_create_forks() == 0)
		return (0);
	if (ft_create_all_mutex() == 0)
		return (0);
	return (1);
}

/**
 * @brief This is the entry point of the philosopher's program.
 * 
 * @param ac 
 * @param av 
 * @param envp 
 * @return int 
 */
int	main(int ac, char **av, char **envp)
{
	t_data	data;

	if (init_data(&data, ac, av, envp) != 0)
		return (0);
	if (prepare_program(&data) == 0)
	{
		ft_free_all_ref();
		return (0);
	}
	ft_create_thread_philo();
	ft_join_thread_philo();
	safe_quit_philo();
	return (0);
}

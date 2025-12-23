/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_forks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 10:53:22 by apayet            #+#    #+#             */
/*   Updated: 2022/07/28 13:34:02 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/**
 * @brief Set the error create fork object
 * 
 * @param cstm_error A message to be printed and notice the user a failed 
 * @param bool 		The condition to use when call
 * @return int 		Return the  value for end the
 * 					instruction if 1 there is an error
 */
static int	set_error_create_fork(char *cstm_error, int bool)
{
	if (bool != 0)
	{
		return (1);
		printf("Error\n");
		printf("%s", cstm_error);
		ft_get_data_addr((t_data *)0)->flag.error = 1;
		return (1);
	}
	return (0);
}

int	ft_create_forks(void)
{
	int		i;
	int		cur_state;
	t_data	*data;

	data = ft_get_data_addr((t_data *)0);
	data->forks = ft_malloc(data, sizeof(t_fork), data->nbr_of_philo);
	if (set_error_create_fork("Malloc failed\n", data->forks == (t_fork *)0))
		return (0);
	i = 0;
	cur_state = 0;
	while (i < data->nbr_of_philo)
	{
		data->forks[i].id = i;
		cur_state = pthread_mutex_init(ft_get_mutex(i), NULL);
		if (set_error_create_fork("mutex init", cur_state != 0))
			return (0);
		i++;
	}
	return (1);
}

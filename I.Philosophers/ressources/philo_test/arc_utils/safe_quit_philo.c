/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_quit_philo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:43:35 by apayet            #+#    #+#             */
/*   Updated: 2022/07/27 16:40:35 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/**
 * @brief This function permit to exit the philo program,
 * 			It is designed to be used at the end of the  main functgion
 * 		ATTENTION POINT :
 * 			Need to be called after the function called prepare_program
 * 
 * @return int the value to be returned to the shell 
 */
int	safe_quit_philo(void)
{
	ft_check_fork_state();
	ft_destroy_forks();
	ft_destroy_all_mutex();
	ft_free_all_ref();
	return (0);
}

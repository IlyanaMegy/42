/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_all_mutex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:46:10 by apayet            #+#    #+#             */
/*   Updated: 2022/08/01 11:41:05 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/** Need to check mutex lock check destroy**/

static void	ft_destroy_mutex_printer(void)
{
	pthread_mutex_destroy(ft_get_m_writer());
}

static void	ft_destroy_mutex_death(void)
{
	pthread_mutex_destroy(ft_get_m_death());
}

/**
 * @brief Need to check lock death destruction
 * 
 */
void	ft_destroy_all_mutex(void)
{
	ft_destroy_mutex_printer();
	ft_destroy_mutex_death();
}

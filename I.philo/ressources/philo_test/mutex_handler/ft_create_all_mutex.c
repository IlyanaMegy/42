/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_all_mutex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:44:05 by apayet            #+#    #+#             */
/*   Updated: 2022/08/01 11:43:10 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_create_all_mutex(void)
{
	if (ft_create_mutex_printer() == 0)
		return (0);
	if (ft_create_mutex_lock_check() == 0)
		return (0);
	if (ft_create_mutex_death() == 0)
		return (0);
	return (1);
}

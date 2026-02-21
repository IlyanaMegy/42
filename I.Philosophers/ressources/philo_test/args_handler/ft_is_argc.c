/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_argc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:47:17 by apayet            #+#    #+#             */
/*   Updated: 2022/05/25 10:47:10 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/**
 * @brief This function determine if the number of args is okay
 * 
 * @return int Boolean representation
 */
int	ft_is_argc(void)
{
	return (ft_get_ac() == 5 || ft_get_ac() == 6);
}

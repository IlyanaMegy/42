/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_idright_from_philo.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:35:57 by apayet            #+#    #+#             */
/*   Updated: 2022/07/21 15:02:24 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_get_idright_from_philo(int id_philo)
{
	int	nbr_of_philo;

	nbr_of_philo = ft_get_data_addr((t_data *)0)->nbr_of_philo;
	if (id_philo == 1)
		return (nbr_of_philo - 1);
	return (id_philo - 2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_populate_philo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 10:53:16 by apayet            #+#    #+#             */
/*   Updated: 2022/08/01 11:08:50 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/**
 * @brief This function create the memory for the philo
 * Return 0 if fails and 1 if okay
 */
int	ft_populate_philo(void)
{
	t_philo	*philo;
	t_clist	*node;
	int		i;

	i = 1;
	while (i <= ft_get_data_addr((t_data *)0)->nbr_of_philo)
	{
		philo = ft_malloc(ft_get_data_addr((t_data *)0), sizeof(t_philo), 1);
		if (!philo)
			return (0);
		ft_memset(&philo[0], 0, sizeof(t_philo));
		philo->id = i;
		node = ft_clstnew((void *)&philo[0]);
		if (node == (t_clist *)0)
			return (0);
		ft_clstadd_back(&(ft_get_data_addr((t_data *)0)->philosopher), node);
		node = (t_clist *)0;
		i++;
	}
	ft_get_philo_clist_addr(ft_get_data_addr((t_data *)0)->philosopher);
	return (1);
}

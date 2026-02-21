/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_philo_by_index.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:20:51 by apayet            #+#    #+#             */
/*   Updated: 2022/07/27 16:56:50 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_philo	*ft_get_philo_by_index(int index)
{
	t_clist	*lst;
	t_philo	*philo;

	lst = ft_get_data_addr((t_data *)0)->philosopher;
	while (lst->is_last != 1)
	{
		philo = (t_philo *)lst->content;
		if (index == philo->id)
			return (philo);
		lst = lst->next;
	}
	return ((t_philo *)0);
}

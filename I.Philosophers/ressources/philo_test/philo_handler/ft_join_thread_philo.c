/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_thread_philo.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:10:10 by apayet            #+#    #+#             */
/*   Updated: 2022/07/27 17:29:25 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_join_thread_philo(void)
{
	t_clist	*philo_clst;
	t_philo	*element;

	philo_clst = ft_get_philo_clist_addr((t_clist *)0);
	while (philo_clst->is_last != 1)
	{
		element = (t_philo *)philo_clst->content;
		pthread_join(element->thread_id, NULL);
		philo_clst = philo_clst->next;
	}
	element = (t_philo *)philo_clst->content;
	pthread_join(element->thread_id, NULL);
}

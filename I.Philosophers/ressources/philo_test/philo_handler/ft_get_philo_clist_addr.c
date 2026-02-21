/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_philo_clist_addr.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:42:29 by apayet            #+#    #+#             */
/*   Updated: 2022/07/27 17:28:04 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_clist	*ft_get_philo_clist_addr(t_clist *p_philo_clst)
{
	static t_clist	*philo_clst = (t_clist *)0;

	if (p_philo_clst != (t_clist *)0)
		philo_clst = p_philo_clst;
	return (philo_clst);
}

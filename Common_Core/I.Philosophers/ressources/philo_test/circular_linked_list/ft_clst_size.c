/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clst_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:09:48 by apayet            #+#    #+#             */
/*   Updated: 2022/05/23 15:03:20 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_clst_size(t_clist *lst)
{
	t_clist	*cur;
	int		i;

	i = 1;
	cur = lst;
	if (!cur)
		return (0);
	while (cur->is_last != 1)
	{
		cur = cur->next;
		i++;
	}
	return (i);
}

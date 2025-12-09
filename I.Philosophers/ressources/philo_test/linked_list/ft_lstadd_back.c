/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:55:02 by apayet            #+#    #+#             */
/*   Updated: 2022/05/16 16:02:02 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_lstadd_back(t_list **alst, t_list *new_bloc)
{
	t_list	*cur;

	if (!alst || !new_bloc)
		return ;
	if (!*alst)
	{
		*alst = new_bloc;
		return ;
	}
	cur = *alst;
	while (cur->next)
		cur = cur->next;
	cur->next = new_bloc;
}

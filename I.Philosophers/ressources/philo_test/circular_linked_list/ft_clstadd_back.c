/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:03:53 by apayet            #+#    #+#             */
/*   Updated: 2022/05/25 14:08:35 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	ft_second_link(t_clist **alst, t_clist *new_bloc)
{
	t_clist	*cur;

	cur = *alst;
	cur->is_first = 1;
	cur->is_last = 0;
	cur->next = new_bloc;
	cur->previous = new_bloc;
	new_bloc->is_first = 0;
	new_bloc->is_last = 1;
	new_bloc->previous = cur;
	new_bloc->next = cur;
}

static void	ft_other_link(t_clist **alst, t_clist *new_bloc)
{
	t_clist	*cur;
	t_clist	*head;

	cur = *alst;
	head = *alst;
	while (cur->is_last == 0)
			cur = cur->next;
	cur->is_first = 0;
	cur->is_last = 0;
	cur->next = new_bloc;
	new_bloc->previous = cur;
	new_bloc->is_last = 1;
	new_bloc->is_first = 0;
	new_bloc->next = head;
	head->previous = new_bloc;
}

void	ft_clstadd_back(t_clist **alst, t_clist *new_bloc)
{
	t_clist	*cur;

	if (!alst || !new_bloc)
		return ;
	if (!*alst)
	{
		*alst = new_bloc;
		return ;
	}
	cur = *alst;
	if (ft_check_integrity_one_node(cur))
		ft_second_link(&cur, new_bloc);
	else
		ft_other_link(&cur, new_bloc);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 11:23:52 by ilymegy           #+#    #+#             */
/*   Updated: 2023/09/24 11:23:54 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"
#include "../inc/libft.h"

void	s_move(t_list **pile)
{
	t_list	*node;
	t_list	*third_node;

	if (pile == NULL)
		return ;
	if (*pile == NULL || (*pile)->next == NULL)
		return ;
	node = *pile;
	third_node = (*pile)->next->next;
	*pile = (*pile)->next;
	(*pile)->next = node;
	(*pile)->next->next = third_node;
}

void	sa(t_list **a)
{
	s_move(a);
}

void	sb(t_list **b)
{
	s_move(b);
}

void	ss(t_list **a, t_list **b)
{
	s_move(a);
	s_move(b);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundred_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 11:09:41 by ilymegy           #+#    #+#             */
/*   Updated: 2023/09/24 11:09:43 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"
#include "../inc/libft.h"

void	push_to_b(t_list **a, t_list **b, t_cmd *cmd)
{
	t_list	*lst;
	size_t	mid;

	lst = *a;
	mid = ft_lstsize(lst) / 2;
	while (less_than_mid(lst, mid))
	{
		if (lst->content->index < mid)
		{
			p_move(a, b);
			commande(8, &cmd);
		}
		else
			print_n_update(3, &cmd, a, ra);
		lst = *a;
	}
}

void	biggest_push_to_b(t_list **a, t_list **b, t_cmd *cmd)
{
	t_list	*lst;
	size_t	mid;

	lst = *a;
	mid = ft_lstsize(lst) / 2;
	while (lst->content->index >= mid)
	{
		p_move(a, b);
		commande(8, &cmd);
		lst = *a;
	}
}

void	sec_push_to_b(t_list **a, t_list **b, t_cmd *cmd)
{
	t_list	*lst;
	size_t	mid;

	lst = *a;
	mid = ft_lstsize(lst) / 2;
	while (lst->content->index < mid)
	{
		p_move(a, b);
		commande(8, &cmd);
		lst = *a;
	}
}

void	push_to_a(t_list **s_a, t_list **s_b, t_cmd *cmd)
{
	t_list	*b;
	size_t	smoler_idx;
	size_t	mid_b;

	b = *s_b;
	mid_b = ft_lstsize(b) / 2;
	smoler_idx = get_smoler(*s_b);
	while (b)
	{
		if (b->content->index == smoler_idx)
		{
			smoler_idx++;
			p_move(s_b, s_a);
			commande(7, &cmd);
			print_n_update(3, &cmd, s_a, ra);
		}
		else if (b->content->index >= mid_b)
		{
			p_move(s_b, s_a);
			commande(7, &cmd);
		}
		else
			print_n_update(4, &cmd, s_b, rb);
		b = *s_b;
	}
}

void	hundred_or_less(t_list **a, t_list **b, t_cmd *cmd)
{
	size_t	mid;

	mid = ft_lstsize(*a) / 2;
	push_to_b(a, b, cmd);
	push_to_a(a, b, cmd);
	while (!sorted_half(0, mid - 1, *a))
	{
		sec_push_to_b(a, b, cmd);
		push_to_a(a, b, cmd);
	}
	biggest_push_to_b(a, b, cmd);
	push_to_a(a, b, cmd);
	while (!sorted_half(mid, ft_lstsize(*a) - 1, *a))
	{
		biggest_push_to_b(a, b, cmd);
		push_to_a(a, b, cmd);
	}
}

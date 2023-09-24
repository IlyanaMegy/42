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

int	find_median(t_list *lst)
{
	size_t	len;
	int		mid;

	len = ft_lstsize(lst);
	mid = 0;
	while (lst->next)
	{
		if (lst->content->index == len / 2)
		{
			mid = lst->content->nb;
			break ;
		}
		lst = lst->next;
	}
	return (mid);
}

int	less_than_mid(t_list *lst, int mid)
{
	while (lst->next)
	{
		if (lst->content->nb < mid)
			return (1);
		lst = lst->next;
	}
	if (lst->content->nb < mid)
		return (1);
	return (0);
}

void	first_sort(t_list **a, t_list **b, t_cmd *cmd, int mid)
{
	t_list	*lst;

	lst = *a;
	while (ft_lstsize(lst) > 3)
	{
		while (lst->content && less_than_mid(lst, mid))
		{
			if (lst->content->nb < mid)
			{
				p_move(a, b);
				commande(7, &cmd);
			}
			else
			{
				print_n_update(3, &cmd, a, ra);
			}
			lst = *a;
		}
		lst = *a;
		get_index(lst);
		mid = find_median(lst);
	}
	three_or_less(a, 'a', cmd);
}

void	hundred_or_less(t_list **a, t_list **b, t_cmd *cmd)
{
	first_sort(a, b, cmd, find_median(*a));
	p_lsts(*a, *b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smol_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 10:59:22 by ilymegy           #+#    #+#             */
/*   Updated: 2023/09/24 10:59:28 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"
#include "../inc/libft.h"

void	sort_three(t_list **lst, t_cmd *cmd)
{
	t_stack	*second;
	t_stack	*third;

	while (!in_order(*lst, 'a'))
	{
		second = (*lst)->next->content;
		third = (*lst)->next->next->content;
		if ((*lst)->content->nb > second->nb)
		{
			if ((*lst)->content->nb > third->nb)
				print_n_update(3, &cmd, lst, ra);
			else
				print_n_update(1, &cmd, lst, sa);
		}
		else if (second->nb > (*lst)->content->nb && second->nb > third->nb)
			print_n_update(5, &cmd, lst, rra);
	}
}

int	three_or_less(t_list **lst, char pile, t_cmd *cmd)
{
	size_t	size;

	size = ft_lstsize(*lst);
	if (size == 2 && !in_order(*lst, pile))
	{
		if (pile == 'a')
			sa(lst);
		else
			sb(lst);
	}
	else if (size == 3)
		sort_three(lst, cmd);
	return (0);
}

void	five_or_less(t_list **a, t_list **b, t_cmd *cmd)
{
	create_stack_b(a, b, cmd);
	if (three_or_less(a, 'a', cmd) || three_or_less(b, 'b', cmd))
		finish_prog(*a, *b, cmd, "");
	while ((*b))
	{
		commande(7, &cmd);
		p_move(b, a);
	}
}
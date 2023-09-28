/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 11:16:54 by ilymegy           #+#    #+#             */
/*   Updated: 2023/09/24 11:16:56 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"
// int	in_order(t_list *lst, char pile)
// {
// 	int	max_value;

// 	if (ft_lstsize(lst) == 1)
// 		return (1);
// 	max_value = lst->content->nb;
// 	lst = lst->next;
// 	while (lst)
// 	{
// 		if (pile == 'a' && max_value < lst->content->nb)
// 			max_value = lst->content->nb;
// 		else if (pile == 'b' && max_value > lst->content->nb)
// 			max_value = lst->content->nb;
// 		else
// 			return (0);
// 		lst = lst->next;
// 	}	
// 	return (1);
// }

// int	push_swap(t_list **s_a, t_list **s_b, t_cmd *cmd)
// {
// 	int	err;

// 	err = 0;
// 	if (ft_lstsize(*s_a) <= 3)
// 		err = three_or_less(s_a, 'a', cmd);
// 	else if (ft_lstsize(*s_a) <= 5)
// 		five_or_less(s_a, s_b, cmd);
// 	else if (ft_lstsize(*s_a) <= 500)
// 		hundred_or_less(s_a, s_b, cmd);
// 	if (err)
// 		finish_prog(*s_a, *s_b, cmd, "Error\n");
// 	return (1);
// }

/*
** get list of numbers in sorted order for real.
*/
void	do_sort(t_stack *stack, t_tools *tools)
{
	if (all_good(stack->b, stack->a))
		return;
	ft_printf("tools total nb = %d\n", tools->total_num);
	if (ft_pslstsize(stack->a) <= 5)
		smol_sort(stack, tools, ft_pslstsize(stack->a));
}

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

// void	resend_to_b(t_stack *s, t_tools *t, int limit)
// {
// 	while ((s->a->idx <= limit)
// 		&& (s->a->idx >= t->a.nxt_idx))
// 		push(&s->a, &s->b, &s->instr, 'b');
// }

// void	return_half_to_a(t_stack *stack, t_tools *t, int limit)
// {
// 	int	size_b;

// 	size_b = ft_pslstsize(stack->b);
// 	if (size_b < 50)
// 	{
// 		finish_sorting(stack, t);
// 		return ;
// 	}
// 	start_sorting(stack, t);
// 	resend_to_b(stack, t, limit);
// 	return_half_to_a(stack, t, limit);
// }

/*
* get list of numbers in sorted order for real.
*/
void	do_sort(t_stack *stack, t_tools *tools)
{
	if (is_sorted(stack->a) && is_full(stack->a, tools->total_num))
		return ;
	if (ft_pslstsize(stack->a) <= 5)
		smol_sort(stack, tools, ft_pslstsize(stack->a));
	// else
	// {
	// 	half_to_b(stack, tools);
	// 	return_half_to_a(stack, tools, tools->b.high_idx);
	// }
	do_sort(stack, tools);
}

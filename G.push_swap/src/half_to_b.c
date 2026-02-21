/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   half_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:24:49 by ilymegy           #+#    #+#             */
/*   Updated: 2023/10/03 15:24:52 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

/*
* is there any small number in stack a ?
*/
int	any_smol_in_stack_a(t_ps *stack_a, t_tools *t)
{
	while (stack_a != NULL)
	{
		if (stack_a->idx <= t->a.mid_idx)
			if (stack_a->idx >= t->a.nxt_idx)
				return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

/*
* sending to stack b.
*/
void	send_to_b_init(t_stack *s, t_tools *t)
{
	push(&s->a, &s->b, &s->instr, 'b');
	if (s->b->idx > t->b.high_idx)
		t->b.high_idx = s->b->idx;
	if (s->b->idx < t->b.low_idx)
		t->b.low_idx = s->b->idx;
}

/*
* sending smallers to stack b.
*/
void	send_smolers_to_b(t_stack *s, t_tools *t, int len_a)
{
	int	rotations;
	int	i;

	i = 0;
	rotations = 0;
	while ((i < len_a) && (any_smol_in_stack_a(s->a, t)))
	{
		if (s->a->idx <= t->a.mid_idx)
			send_to_b_init(s, t);
		else
		{
			rotate(&s->a, &s->instr, 'a');
			rotations++;
		}
		i++;
	}
	if (t->a.nxt_idx)
	{
		i = 0;
		while (i < rotations)
		{
			reverse_rotate(&s->a, &s->instr, 'a');
			i++;
		}
	}
}

/*
* initializing values of tools of stack b.
*/
void	init_b_values(t_stack *s, t_tools *t, int *len_a)
{
	*len_a = ft_pslstsize(s->a);
	t->b.high_idx = INT_MIN;
	t->b.low_idx = INT_MAX;
	t->a.mid_idx = mid_idx(t->a.high_idx, t->a.nxt_idx);
}

/*
* sending half of stack a to stack b.
*/
void	half_to_b(t_stack *stack, t_tools *tools)
{
	int	len_a;

	init_b_values(stack, tools, &len_a);
	if (tools->a.high_idx - tools->a.nxt_idx < 1)
		while (stack->a->idx > 0)
			send_to_b_init(stack, tools);
	else
		send_smolers_to_b(stack, tools, len_a);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 16:07:54 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/06/09 20:10:44 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

static void	send_next_bigger_to_a(t_stack *s, t_tools *t)
{
	push(&s->b, &s->a, &s->instr, 'a');
	t->b.high_idx--;
	if (s->a->idx == t->a.nxt_idx)
	{
		rotate(&s->a, &s->instr, 'a');
		t->a.nxt_idx++;
	}
}

static void	send_next_smaller_to_a(t_stack *s, t_tools *t)
{
	push(&s->b, &s->a, &s->instr, 'a');
	rotate(&s->a, &s->instr, 'a');
	t->a.nxt_idx++;
	t->b.low_idx++;
}

static void	define_b_values(t_stack *s, t_tools *t)
{
	t_ps	*s_b;

	s_b = s->b;
	t->b.high_idx = INT_MIN;
	t->b.low_idx = INT_MAX;
	while (s_b)
	{
		if (s_b->idx > t->b.high_idx)
			t->b.high_idx = s_b->idx;
		if (s_b->idx < t->b.low_idx)
			t->b.low_idx = s_b->idx;
		s_b = s_b->next;
	}
	t->b.mid_idx = mid_idx(t->b.high_idx, t->b.low_idx);
}

void	finish_sorting(t_stack *s, t_tools *t)
{
	int	len_b;

	len_b = ft_pslstsize(s->b);
	define_b_values(s, t);
	if (len_b == 0)
	{
		order_a(s, t);
		return ;
	}
	else if (len_b == 1)
		push(&s->b, &s->a, &s->instr, 'a');
	else if (s->b->idx == t->a.nxt_idx)
		send_next_smaller_to_a(s, t);
	else if (s->b->idx == t->b.high_idx)
		send_next_bigger_to_a(s, t);
	else if (reverse_rotation_is_quicker(s->b, t->a.nxt_idx))
		reverse_rotate(&s->b, &s->instr, 'b');
	else
		rotate(&s->b, &s->instr, 'b');
	finish_sorting(s, t);
}

void	start_sorting(t_stack *s, t_tools *t)
{
	int	len_b;

	len_b = ft_pslstsize(s->b);
	define_b_values(s, t);
	if (len_b == 0)
		return ;
	if ((s->b->idx > t->b.mid_idx) || (len_b == 1))
		push(&s->b, &s->a, &s->instr, 'a');
	else if (s->b->idx == t->a.nxt_idx)
		send_next_smaller_to_a(s, t);
	else if (reverse_rotation_is_quicker(s->b, t->a.nxt_idx))
		reverse_rotate(&s->b, &s->instr, 'b');
	else
		rotate(&s->b, &s->instr, 'b');
	start_sorting(s, t);
}

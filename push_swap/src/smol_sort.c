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

/*
* defining first second and last numbers of the given stack.
*/
void	define_numbers(int *first, int *second, int *last, t_ps *s)
{
	*first = s->content;
	*second = s->next->content;
	while (s->next != NULL)
		s = s->next;
	*last = s->content;
}

/*
* sorting stack of three numbers.
*/
void	sort_three(t_stack *stack, int *first, int *second, int *last)
{
	if (is_sorted(stack->a))
		return ;
	if ((*first > *second && *last > *second && *first < *last)
		|| (*first > *second && *last < *second && *first > *last)
		|| (*first < *second && *last < *second && *first < *last))
		swap(&stack->a, &stack->instr, 'a');
	if (stack->b->next)
		if (stack->b->idx < stack->b->next->idx)
			swap(&stack->b, &stack->instr, 'b');
	define_numbers(first, second, last, stack->a);
	if (*first > *second && *last > *second && *first > *last)
		rotate(&stack->a, &stack->instr, 'a');
	if (*first < *second && *last < *second && *first > *last)
		reverse_rotate(&stack->a, &stack->instr, 'a');
}

void	send_to_b(t_stack *stack, t_tools *tools, int total_nb)
{
	if (ft_pslstsize(stack->a) == 3)
		return ;
	if ((stack->a->idx == 0) || (stack->a->idx == 1))
	{
		tools->a.high_idx--;
		push(&stack->a, &stack->b, &stack->instr, 'b');
	}
	else
		rotate(&stack->a, &stack->instr, 'a');
	send_to_b(stack, tools, total_nb);
}

void	return_to_a(t_stack *stack)
{
	if (!stack->b)
		return ;
	if (stack->b->next)
		if (stack->b->idx < stack->b->next->idx)
			swap(&stack->b, &stack->instr, 'b');
	push(&stack->b, &stack->a, &stack->instr, 'a');
	if (stack->a->idx > stack->a->next->idx)
		swap(&stack->a, &stack->instr, 'a');
	return_to_a(stack);
}

/*
* doing smol sort here.
*/
void	smol_sort(t_stack *s, t_tools *tools, int total_nb)
{
	int	first;
	int	second;
	int	last;

	(void)tools;
	p_lsts(s->a, s->b);
	if (is_sorted(s->a) && is_full(s->a, total_nb))
		return ;
	if (ft_pslstsize(s->a) == 2)
	{
		swap(&s->a, &s->instr, 'a');
		return ;
	}
	if (ft_pslstsize(s->a) == 3)
	{
		define_numbers(&first, &second, &last, s->a);
		sort_three(s, &first, &second, &last);
		return_to_a(s);
	}
	else
		send_to_b(s, tools, total_nb);
	smol_sort(s, tools, total_nb);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 11:11:06 by ilymegy           #+#    #+#             */
/*   Updated: 2023/09/24 11:11:07 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

/*
** get list of numbers in sorted order.
*/
int	*fill_ordered_array(t_ps *stack_a, int total)
{
	int	*ordered_array;
	int	i;

	ordered_array = (int *)malloc((total) * sizeof(int));
	if (!ordered_array)
		end_prog("", 1);
	i = 0;
	while (i < (total))
	{
		ordered_array[i] = stack_a->content;
		i++;
		stack_a = stack_a->next;
	}
	quick_sort(ordered_array, (total));
	return (ordered_array);
}

/*
** well, it finds the index.
*/
int	find_index(t_stack *stack, t_tools *tools, int i)
{
	if (tools->ordered_array[i] == stack->a->content)
		return (i);
	return (find_index(stack, tools, (i + 1)));
}

/*
** set all indexes of each number of the list.
*/
void	get_index(t_stack *stack, t_tools *tools)
{
	if (stack->a->next == NULL)
	{
		stack->a->idx = find_index(stack, tools, 0);
		rewind(&stack->a);
		return ;
	}
	stack->a->idx = find_index(stack, tools, 0);
	stack->a = stack->a->next;
	get_index(stack, tools);
}

/*
** initializing tools of stack_a : 
** -> total num
** -> ordered array
** -> higher index
** -> next index to order
** -> mid index
*/
void	init_tools(t_ps *stack_a, t_tools *t, int argc)
{
	ft_memset(t, 0, sizeof(*t));
	t->total_num = argc;
	t->ordered_array = fill_ordered_array(stack_a, t->total_num);
	t->a.high_idx = t->total_num - 1;
	t->a.nxt_idx = 0;
	t->a.mid_idx = mid_idx(t->a.high_idx, t->a.nxt_idx);
}

/*
** initializing stack_a, tools of stack_a, set all indexes.
*/
void	init(t_stack *stack, t_tools *tools, int ac, char **av)
{
	init_stack_a(ac, av, &stack->a);
	init_tools(stack->a, tools, ac);
	get_index(stack, tools);
}

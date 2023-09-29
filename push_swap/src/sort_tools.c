#include "../inc/pushswap.h"

/*
** get mid index.
*/
int	mid_idx(int bigger_idx, int smoler_idx)
{
	return (smoler_idx + ((bigger_idx - smoler_idx) / 2));
}

/*
** go back to first element of the list.
*/
void	rewind(t_ps **stack_to_rewind)
{
	t_ps	*stack;

	stack = *stack_to_rewind;
	while (stack->prev != NULL)
		stack = stack->prev;
	*stack_to_rewind = stack;
}

int	last_num_index(t_ps *stack)
{
	while (stack->next != NULL)
		stack = stack->next;
	return (stack->idx);
}

void	order_a(t_stack *stack, t_tools *t)
{
	if (stack->a->idx == 0)
		rotate(&stack->a, &stack->instr, 'a');
	while (((stack->a->idx + 1) == (stack->a->next->idx))
		&& ((stack->a->idx - 1) == last_num_index(stack->a)))
		rotate(&stack->a, &stack->instr, 'a');
	if (((stack->a->idx - 1) == last_num_index(stack->a)))
		rotate(&stack->a, &stack->instr, 'a');
	t->a.nxt_idx = last_num_index(stack->a) + 1;
}
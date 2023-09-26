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
	while (stack->previous != NULL)
		stack = stack->previous;
	*stack_to_rewind = stack;
}
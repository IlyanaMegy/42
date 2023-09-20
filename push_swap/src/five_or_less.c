#include "../inc/pushswap.h"
#include "../inc/libft.h"

void	five_or_less(t_list **a, t_list **b, t_cmd *cmd)
{
	create_stack_b(a, b, cmd);
	if (three_or_less(a, 'a', cmd) || three_or_less(b, 'b', cmd))
		finish_prog(*a, *b, cmd,  "");
	while ((*b))
	{
		commande(7, &cmd);
		p_move(b, a);
	}
}
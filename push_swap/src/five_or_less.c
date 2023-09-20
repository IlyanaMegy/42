#include "../inc/pushswap.h"
#include "../inc/libft.h"

void	five_or_less(t_list **a, t_list **b, t_cmd *cmd)
{
	// int mid;

	create_stack_b(a, b, cmd);
	if (three_or_less(a, 'a', cmd) || three_or_less(b, 'b', cmd))
		finish_prog(*a, *b, cmd,  "");
	while ((*b))
	{
		commande(8, &cmd);
		p_move(a, b);
	}
	// p_lsts(*a, *b);
	// while (!all_good(*a, *b) && ft_lstsize(*a) > 3)
	// 	first_sort(a, b);
	// if (!in_order(*a))
	// 	sa(a);
	// if (!in_order(*b) && ft_lstsize(*b) == 2)
	// {
	// 	sb(b);
	// 	p_move(b, a, 'a');
	// 	p_move(b, a, 'a');
	// 	return;
	// }
	// while (!all_good(*a, *b))
	// 	push_back(a, b);
}
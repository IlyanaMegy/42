#include "../inc/pushswap.h"
#include "../inc/libft.h"

void	r_move(t_list **pile)
{
	t_list	*node;

	if (pile == NULL || *pile == NULL)
		return ;
	node = *pile;
	*pile = (*pile)->next;
	node->next = NULL;
	ft_lstadd_back(pile, node);
}

void	ra(t_list **a)
{
	r_move(a);
}

void	rb(t_list **b)
{
	r_move(b);
}

void	rr(t_list **a, t_list **b)
{
	r_move(a);
	r_move(b);
}
#include "../inc/pushswap.h"
#include "../inc/libft.h"

void	rr_move(t_list **pile)
{
	t_list	*node;

	if (pile == NULL || *pile == NULL)
		return ;
	node = *pile;
	if (node->next == NULL)
		return ;
	while (node->next->next != NULL)
		node = node->next;
	ft_lstadd_front(pile, node->next);
	node->next = NULL;
}

void	rra(t_list **a)
{
	rr_move(a);
	ft_printf("rra\n");
}

void	rrb(t_list **b)
{
	rr_move(b);
	ft_printf("rrb\n");
}

void	rrr(t_list **a, t_list **b)
{
	rr_move(a);
	rr_move(b);
	ft_printf("rrr\n");
}
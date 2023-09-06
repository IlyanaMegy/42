#include "../inc/pushswap.h"
#include "../inc/libft.h"


void	p_move(t_list **src, t_list **dest, char p)
{
	t_list *node;
	
	if (src == NULL)
		return ;
	node = *src;
	*src = (*src)->next;
	node->next = NULL;
	ft_lstadd_front(dest, node);
	if (p == 'b')
		ft_printf("pb\n");
	else
		ft_printf("pa\n");
	return;
}
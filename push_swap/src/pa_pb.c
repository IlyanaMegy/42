#include "../inc/pushswap.h"
#include "../inc/libft.h"

int	p_move(t_list **src, t_list **dest, char p)
{
	t_list *node;

	node = *src;
	*src = (*src)->next;
	node->next = NULL;
	ft_lstadd_front(dest, node);
	if (p == 'b')
		ft_printf("pb\n");
	else
		ft_printf("pa\n");
	return (0);
}
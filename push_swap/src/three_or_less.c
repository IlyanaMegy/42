#include "../inc/pushswap.h"
#include "../inc/libft.h"

int	sort_three(t_list **a)
{
	t_stack *first;
	t_stack *second;
	t_stack *third;

	while (!in_order(*a))
	{
		first = (*a)->content;
		second = (*a)->next->content;
		third = (*a)->next->next->content;
		if (first->nb > second->nb && first->nb > third->nb)
			ra(a);
		else if (second->nb > first->nb && second->nb > third->nb)
			rra(a);
		else if (first->nb > second->nb)
			sa(a);
		else
			return (1);
	}
	return (0);
}

void	three_or_less(t_list **a)
{
	size_t	size;

	size = ft_lstsize(*a);
	if (size == 2 && !in_order(*a))
		sa(a);
	else if (size == 3)
		sort_three(a);
}
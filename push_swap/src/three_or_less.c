#include "../inc/pushswap.h"
#include "../inc/libft.h"

int	sort_three(t_list **lst, char pile)
{
	t_stack *first;
	t_stack *second;
	t_stack *third;

	if (pile == 'a')
		while (!in_order(*lst, pile))
		{
			first = (*lst)->content;
			second = (*lst)->next->content;
			third = (*lst)->next->next->content;
			if (first->nb > second->nb)
			{
				if (first->nb > third->nb)
					ra(lst);
				else
					sa(lst);
			}
			else if (second->nb > first->nb && second->nb > third->nb)
				rra(lst);
			else
				return (1);
		}
	else
		return (1);
	return (0);
}

int	three_or_less(t_list **lst, char pile)
{
	size_t	size;
	int err;

	err = 0;
	size = ft_lstsize(*lst);
	if (size == 2 && !in_order(*lst, pile))
	{
		if (pile == 'a')
			sa(lst);
		else
			sb(lst);
	}
	else if (size == 3)
		err = sort_three(lst, pile);
	if (err)
		return 1;
	return 0;
}
#include "../inc/pushswap.h"
#include "../inc/libft.h"

int	all_good(t_list *s_a, t_list *s_b)
{
	int	max_value;
	t_list *lst;

	if (s_b != NULL)
		return (0);
	if (ft_lstsize(s_a) == 1)
		return (1);
	lst = s_a;
	max_value = s_a->content->nb;
	lst = lst->next;
	while (lst)
	{
		if (max_value < lst->content->nb)
			max_value = lst->content->nb;
		else
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	in_order(t_list *lst)
{
	int	max_value;

	if (ft_lstsize(lst) == 1)
		return (1);
	max_value = lst->content->nb;
	lst = lst->next;
	while (lst)
	{
		if (max_value < lst->content->nb)
			max_value = lst->content->nb;
		else
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	push_swap(t_list **s_a, t_list **s_b)
{
	// print_lst(*s_a, 'a');
	// print_lst(*s_b, 'b');
	print_lists(*s_a, *s_b);
	if ((*s_b) != NULL)
		return (0);
	p_move(s_a, s_b, 'b');
	print_lists(*s_a, *s_b);
	p_move(s_b, s_a, 'b');
	print_lists(*s_a, *s_b);
	return (1);
}
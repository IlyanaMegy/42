#include "../inc/pushswap.h"
#include "../inc/libft.h"

int	all_good(t_list *s_a, t_list *s_b)
{
	int		max_value;
	t_list	*lst;

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

int	in_order(t_list *lst, char pile)
{
	int	max_value;

	if (ft_lstsize(lst) == 1)
		return (1);
	max_value = lst->content->nb;
	lst = lst->next;
	if (pile == 'a')
		while (lst)
		{
			if (max_value < lst->content->nb)
				max_value = lst->content->nb;
			else
				return (0);
			lst = lst->next;
		}
	else
		while (lst)
		{
			if (max_value > lst->content->nb)
				max_value = lst->content->nb;
			else
				return (0);
			lst = lst->next;
		}
	return (1);
}

int	push_swap(t_list **s_a, t_list **s_b, t_cmd *cmd)
{
	int err;

	err = 0;
	if (ft_lstsize(*s_a) <= 3)
		err = three_or_less(s_a, 'a', cmd);
	else if (ft_lstsize(*s_a) <= 5)
		five_or_less(s_a, s_b, cmd);
	else if (ft_lstsize(*s_a) <= 100)
		hundred_or_less(s_a, s_b, cmd);
	if (err)
		finish_prog(*s_a, *s_b, cmd, "Error\n");
	return (1);
}
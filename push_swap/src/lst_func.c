#include "../inc/pushswap.h"

void	lstadd_back(t_pA **lst, t_pA *new)
{
	t_list	*tmp;

	if (!lst)
	{
		*lst = new;
		return ;
	}
	tmp = ft_lstlast(*(lst));
	tmp->next = new;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}

t_list	*lstlast(t_pA *lst)
{
	t_list	*tmp;

	tmp = lst;
	if (lst)
		while (tmp->next)
			tmp = tmp->next;
	return (tmp);
}

#include "../inc/pushswap.h"

t_pA	*lstnew(int nb)
{
	t_pA	*new;

	new = (t_pA *)malloc(sizeof(t_pA));
	new->nb = nb;
	new->next = NULL;
	return (new);
}

t_pA	*lstlast(t_pA *lst)
{
	t_pA	*tmp;

	tmp = lst;
	if (lst)
		while (tmp->next)
			tmp = tmp->next;
	return (tmp);
}

void	lstadd_back(t_pA **lst, t_pA *new)
{
	t_pA	*tmp;

	if (!lst)
	{
		*lst = new;
		return ;
	}
	tmp = lstlast(*(lst));
	tmp->next = new;
}

void	print_list(t_pA *mylist)
{
	t_pA	*lst;

	lst = mylist;
	while (lst->next)
	{
		ft_printf("%d --> ",lst->nb);
		lst = lst->next;
	}
	ft_printf("%d\n",lst->nb);
}


// void	ft_lstadd_front(t_list **lst, t_list *new)
// {
// 	if (!lst)
// 	{
// 		*lst = new;
// 		return ;
// 	}
// 	new->next = *lst;
// 	*lst = new;
// }



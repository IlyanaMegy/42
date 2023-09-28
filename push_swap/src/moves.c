#include "../inc/pushswap.h"

/*
** swaping the first and second numbers in given stack.
*/
void	swap(t_ps **s, t_list **cmd, char pile)
{
	t_ps	*first;
	t_ps	*sec;

	if (!(*s))
		return ;
	first = *s;
	sec = first->next;
	if (!sec)
		return ;
	first->next = sec->next;
	first->prev = sec;
	if (sec->next)
		sec->next->prev = first;
	sec->next = first;
	sec->prev = NULL;
	*s = sec;
	if (pile == 'a')
		ft_lstadd_back(cmd, ft_lstnew("sa\n"));
	else
		ft_lstadd_back(cmd, ft_lstnew("sb\n"));
}

/*
** shift_up.
*/
void	rotate(t_ps **s, t_list **cmd, char pile)
{
	t_ps	*first;
	t_ps	*last;

	if (!(*s))
		return ;
	first = *s;
	last = *s;
	if (!last->next)
		return ;
	first->next->prev = NULL;
	*s = first->next;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	if (pile == 'a')
		ft_lstadd_back(cmd, ft_lstnew("ra\n"));
	else
		ft_lstadd_back(cmd, ft_lstnew("rb\n"));
}

/*
** shift_down.
*/
void	reverse_rotate(t_ps **s, t_list **cmd, char pile)
{
	t_ps	*first;
	t_ps	*last;

	if (!(*s))
		return ;
	first = *s;
	last = *s;
	while (last->next != NULL)
		last = last->next;
	first->prev = last;
	last->next = first;
	last->prev->next = NULL;
	last->prev = NULL;
	*s = last;
	if (pile == 'a')
		ft_lstadd_back(cmd, ft_lstnew("rra\n"));
	else
		ft_lstadd_back(cmd, ft_lstnew("rrb\n"));
}

/*
** initializing empty stack.
*/
void	init_empty_s(t_ps *dest, t_list **cmd, t_ps **dest_s, char id)
{
	dest->next = NULL;
	dest->prev = NULL;
	*dest_s = dest;
	if (id == 'a')
		ft_lstadd_back(cmd, ft_lstnew("pa\n"));
	else
		ft_lstadd_back(cmd, ft_lstnew("pb\n"));
}

/*
** pushing first nb of stack 1 to stack 2 on top.
*/
void	push(t_ps **src_s, t_ps **dest_s, t_list **cmd, char pile)
{
	t_ps *src;
	t_ps *dest;

	if (!(*src_s))
		return ;
	src = *src_s;
	dest = *dest_s;
	if (!src->next)
		*src_s = NULL;
	else
	{
		*src_s = src->next;
		src->next->prev = NULL;
	}
	if (!dest)
		return (init_empty_s(src, cmd, dest_s, pile));
	dest->prev = src;
	src->next = dest;
	*dest_s = dest->prev;
	if (pile == 'a')
		ft_lstadd_back(cmd, ft_lstnew("pa\n"));
	else
		ft_lstadd_back(cmd, ft_lstnew("pb\n"));
}
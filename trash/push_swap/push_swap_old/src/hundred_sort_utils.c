#include "../inc/pushswap.h"
#include "../inc/libft.h"

int	less_than_mid(t_list *lst, size_t mid)
{
	while (lst->next)
	{
		if (lst->content->index < mid)
			return (1);
		lst = lst->next;
	}
	if (lst->content->index < mid)
		return (1);
	return (0);
}

int	sorted_half(size_t start, size_t end, t_list *lst)
{
	while (lst->content->index != start)
		lst = lst->next;
	while (lst->next && lst->content->index <= end)
	{
		if (lst->next)
			if (lst->content->index > lst->next->content->index)
				return (0);
		lst = lst->next;
	}
	if (lst->content->index == end)
		return (1);
	return (0);
}

size_t	get_smoler(t_list *lst)
{
	int		smol;
	size_t	idx;

	smol = lst->content->nb;
	idx = lst->content->index;
	while (lst->next)
	{
		if (lst->content->nb < smol)
		{
			smol = lst->content->nb;
			idx = lst->content->index;
		}
		lst = lst->next;
	}
	if (lst->content->nb < smol)
	{
		smol = lst->content->nb;
		idx = lst->content->index;
	}
	return (idx);
}

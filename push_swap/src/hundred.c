#include "../inc/pushswap.h"
#include "../inc/libft.h"

int	find_median(t_list *lst)
{
	size_t	len;
	int		mid;

	len = ft_lstsize(lst);
	mid = 0;
	// ft_printf("len/2 = %d\n", len/2);
	while (lst->content)
	{
		// ft_printf("%d = %d\n", lst->content->nb, lst->content->index);
		if (lst->content->index == len / 2)
		{
			mid = lst->content->nb;
			break ;
		}
		lst = lst->next;
	}
	ft_printf("mid = %d\n", mid);
	return (mid);
}

int less_than_mid(t_list *a, int mid)
{
    t_list *lst;

    lst = a;
    while (lst->content)
    {
        if (lst->content->nb < mid)
            return 1;
        lst = lst->next;
    }
    return 0;
}

void	first_sort(t_list **a, t_list **b, t_cmd *cmd, int mid)
{
    t_list *lst;

    lst = *a;
	while (ft_lstsize(*a) > 3)
	{
        while (lst->content && less_than_mid(*a, mid))
        {
            if (lst->content->nb < mid)
            {
                p_move(a, b);
                commande(7, &cmd);
            }
            else
                print_n_update(3, &cmd, a, ra);
            lst = *a;
        }
        p_lsts(*a, *b);
        find_median(*a);
        lst = *a;
	}
}

void	hundred_or_less(t_list **a, t_list **b, t_cmd *cmd)
{
	int mid;

	mid = find_median(*a);
	// while (*a)
	// {
		
	// }
    first_sort(a, b, cmd, mid);
    // p_lsts(*a, *b);
	// ft_printf("mid = %d\nfirst a = %d\nfirst b = %d\ncmd = %d\n", mid,
		// (*a)->content->nb, (*b)->content, cmd->cmd);
}
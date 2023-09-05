#include "../inc/pushswap.h"
#include "../inc/libft.h"


// void	big_n_smol(int *big, int *smol, int *pile)
// {
// 	int	i;

// 	i = 0;
// 	while (pile[i])
// 	{
// 		if (pile[i] > pile[i + 1])
// 			*big = i;
// 		else if (pile[i] < pile[i + 1])
// 			*smol = i;
// 		i++;
// 	}
// }

// int	in_order(t_ps *ps, char pile)
// {
// 	int	*tab;
// 	int	len;
// 	int	i;

// 	i = 0;
// 	if (pile == 'a')
// 	{
// 		tab = ps->intab_pA.tab;
// 		len = ps->intab_pA.nb_nbr;
// 	}
// 	else
// 	{
// 		tab = ps->intab_pB.tab;
// 		len = ps->intab_pB.nb_nbr;
// 	}
// 	if (tab[0])
// 	{
// 		while (tab[i] < tab[i + 1])
// 			i++;
// 		if (i + 1 < len)
// 			return (0);
// 		return (1);
// 	}
// 	return (1);
// }

// void	push_swap(t_ps *ps)
// {
// 	if(ps->intab_pA.tab)
// 		print_tab(ps->intab_pA.tab);
// 	if (in_order(ps, 'a') && !ps->intab_pB.tab[0])
// 	{
// 		ft_printf("in order !\n");
// 		end_prog(ps);
// 	}

// 	else
// 		ft_printf("not in order.\n");
// }

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
	print_lst(*s_a);
	if ((*s_b) != NULL)
		return (0);
	return (1);
}
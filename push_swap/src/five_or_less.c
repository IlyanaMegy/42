#include "../inc/pushswap.h"
#include "../inc/libft.h"


char	smol(int a, int b, int z)
{
	if (a < b && a < z)
		return ('a');
	else if (b < a && b < z)
		return ('b');
	return ('z');
}

char	big(int a, int b, int z)
{
	if (a > b && a > z)
		return ('a');
	else if (b > a && b > z)
		return ('b');
	return ('z');
}

void	cmp_n_push(t_list **s_a, t_list **s_b)
{
	int	a;
	int	b;
	int	c;
	int	z;

	a = (*s_a)->content->nb;
	b = (*s_a)->next->content->nb;
	c = (*s_a)->next->next->content->nb;
	z = (ft_lstlast(*s_a))->content->nb;
	if (smol(a, b, z) == 'z' && c < z)
	{
		ra(s_a);
		sa(s_a);
	}
	if (smol(a, b, z) == 'z' && c > z)
	{
		rra(s_a);
	}
	else if (smol(a, b, z) == 'b')
	{
		if (c < b)
			ra(s_a);
		else
			sa(s_a);
	}
	else if (smol(a, b, z) == 'a')
	{
		p_move(s_a, s_b, 'b');
	}
}

void	five_or_less(t_list **a, t_list **b)
{
	// int mid;

	while (!all_good(*a, *b) && ft_lstsize(*a) >= 3)
	{
		cmp_n_push(a, b);
		p_lsts(*a, *b);
	}
}
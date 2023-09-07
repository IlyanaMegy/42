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

void	push_back(t_list **s_a, t_list **s_b)
{
	int	a;
	int	c;
	int	d;
	int e;

	a = (*s_a)->content->nb;
	c = (*s_b)->content->nb;
	d = (*s_b)->next->content->nb;
	e = (*s_b)->next->next->content->nb;
	if (big(c, d, e)== 'a')
	{
		if (c < a)
		{
			ra(s_a);
			p_move(s_b, s_a, 'a');
			rra(s_a);
		}
		else if (c > a)
			p_move(s_b, s_a, 'a');
	}
	else if (big(c, d, e)== 'b')
		sb(s_b);
	else if (big(c, d, e)== 'c')
		rrb(s_b);
}

void	first_sort(t_list **s_a, t_list **s_b)
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
		rra(s_a);
	else if (smol(a, b, z) == 'b')
	{
		if (c < b)
			ra(s_a);
		else
			sa(s_a);
	}
	else if (smol(a, b, z) == 'a')
		p_move(s_a, s_b, 'b');
}

void	five_or_less(t_list **a, t_list **b)
{
	// int mid;

	create_stack_b(a, b);
	// while (!all_good(*a, *b) && ft_lstsize(*a) >= 3)
	// 	first_sort(a, b);
	// if (!in_order(*a))
	// 	sa(a);
	// if (!in_order(*b) && ft_lstsize(*b) == 2)
	// {
	// 	sb(b);
	// 	p_move(b, a, 'a');
	// 	p_move(b, a, 'a');
	// 	return;
	// }
	// while (!all_good(*a, *b))
	// 	push_back(a, b);
}
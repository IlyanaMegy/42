#include "../inc/pushswap.h"

void	big_n_smol(int *big, int *smol, int *pile)
{
	int	i;

	i = 0;
	while (pile[i])
	{
		if (pile[i] > pile[i + 1])
			*big = i;
		else if (pile[i] < pile[i + 1])
			*smol = i;
		i++;
	}
}

int	in_order(t_ps *ps, char pile)
{
	int	*tab;
	int	len;
	int	i;

	i = 0;
	if (pile == 'a')
	{
		tab = ps->intab_pA.tab;
		len = ps->intab_pA.nb_nbr;
	}
	else
	{
		tab = ps->intab_pB.tab;
		len = ps->intab_pB.nb_nbr;
	}
	if (tab[0])
	{
		while (tab[i] < tab[i + 1])
			i++;
		if (i + 1 < len)
			return (0);
		return (1);
	}
	return (1);
}

void	push_swap(t_ps *ps)
{
	if(ps->intab_pA.tab)
		print_tab(ps->intab_pA.tab);
	if (in_order(ps, 'a') && !ps->intab_pB.tab[0])
	{
		ft_printf("in order !\n");
		end_prog(ps);
	}
		
	else
		ft_printf("not in order.\n");
}
#include "../inc/pushswap.h"

void	big_n_smol(int *big, int *smol, int *pile)
{
	int i;

	i = 0;
	while (pile[i])
	{
		if (pile[i] > pile[i+1])
			*big = i;
		else if(pile[i] < pile[i+1])
			*smol = i;
		i++;
	}

}

int	in_order(int *pile)
{
	int big;
	int smol;

	big = 0;
	smol = 0;
	if (pile[1])
	{
		print_tab(pile);
		big_n_smol(&big, &smol, pile);
		ft_printf("big = %d, smol = %d\n", big, smol);
	}
		
	return (1);
}

void	push_swap(t_ps *ps)
{
	ft_printf("nb_nbr tabpA = %d\n", ps->intab_pA.nb_nbr);
	if (in_order(ps->intab_pA.tab))
		ft_printf("in order !\n");
	else
		ft_printf("not in order.\n");
}
#include "../inc/pushswap.h"

int	in_order(int *pile)
{
	
	ft_printf("pX[1] = %d\n", pile[1]);
	return (1);
}

void	push_swap(t_ps *ps)
{
	if (in_order(ps->intab_pA))
		ft_printf("in order !\n");
	ft_printf("not in order.\n");
}
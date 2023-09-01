#include "../inc/pushswap.h"

void	init_piles(t_pA *pA, t_pB *pB, char **av)
{
	fill_pA(av, &pA);
	// ps->intab_pA.tab = int_tab(ps->pileA, ps, &ps->intab_pA.nb_nbr);
	// ps->intab_pB.tab = int_tab(ps->pileB, ps, &ps->intab_pB.nb_nbr);
}

int	main(int ac, char **av)
{
	t_pA *pA;
	t_pB *pB;
	int pA_len;

	if (ac > 1)
	{
		pA_len = check_args(av);
		if (!pA_len) //pas de nombre ou erreur
		{
			ft_printf("Error\n");
			exit(1);
			return (1);
		}
		if (pA_len == 1) // un seul nombre deja en ordre
		{
			ft_printf("\n");
			exit(0);
			return (0);
		}
		ft_printf("len pA = %d\n", pA_len);
		init_piles(&pA, &pB, av);
		// push_swap(&ps);
		// ft_printf("pA = \n%s\n", ps.pileA);
		// free(ps.pileA);
		// free(ps.intab_pA.tab);
	}
	ft_printf("Error\n");
	exit(1);
	return (1);
}
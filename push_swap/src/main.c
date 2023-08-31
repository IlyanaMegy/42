#include "../inc/pushswap.h"

void	end_prog(t_ps *ps)
{
	free(ps->intab_pA.tab);
	free(ps->pileA);
	exit(0);
}

void	init_piles(t_ps *ps, char **av)
{
	ps->pileA = malloc((sizeof(char) * (ps->len_pA + 1)));
	ps->pileB = malloc((sizeof(char) * (ps->len_pA + 1)));
	if (!(ps->pileB) || !(ps->pileA))
	{
		ft_printf("Error\n");
		exit(1);
	}
	ps->pileB[0] = '\0';
	ps->pileA[0] = '\0';
	fill_pA(av, &(ps->pileA));
	if (!(ps->pileA)[0] || !(ps->pileA))
	{
		free(ps->pileA);
		free(ps->pileB);
		ft_printf("Error\n");
		exit(1);
	}
	ps->intab_pA.tab = int_tab(ps->pileA, ps, &ps->intab_pA.nb_nbr);
	ps->intab_pB.tab = int_tab(ps->pileB, ps, &ps->intab_pB.nb_nbr);
}

int	main(int ac, char **av)
{
	t_ps ps;

	if (ac > 1)
	{
		ps.len_pA = check_args(av);
		if (!ps.len_pA) //pas de nombre ou erreur
		{
			ft_printf("Error\n");
			exit(1);
			return (1);
		}
		if (ps.len_pA == 1) // un seul nombre deja en ordre
		{
			ft_printf("\n");
			exit(1);
			return (1);
		}
		ft_printf("len pA = %d\n", ps.len_pA);
		init_piles(&ps, av);
		push_swap(&ps);
		ft_printf("pA = \n%s\n", ps.pileA);
		free(ps.pileA);
		free(ps.intab_pA.tab);
	}
	ft_printf("Error\n");
	exit(1);
	return (1);
}
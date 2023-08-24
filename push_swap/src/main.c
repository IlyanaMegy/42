#include "../inc/pushswap.h"

void	end_prog(void)
{
	ft_printf("Error\n");
	exit(1);
}

void	init_piles(t_ps *ps, char **av)
{
	(*ps).pileA = malloc((sizeof(char) * ((*ps).len_pA + 1)));
	(*ps).pileA[0] = '\0';
	(*ps).pileB = malloc((sizeof(char) * ((*ps).len_pA + 1)));
	(*ps).pileB[0] = '\0';
	if (!((*ps).pileB) || !((*ps).pileA))
		end_prog();
	fill_pA(av, &((*ps).pileA));
	if (!((*ps).pileA)[0] || !((*ps).pileA))
		end_prog();
}

int	main(int ac, char **av)
{
	t_ps ps;

	if (ac > 1)
	{
		ps.len_pA = check_args(av);
		if (!ps.len_pA)
			end_prog();
		init_piles(&ps, av);
		in_order(ps.pileA, ps.len_pA);
		free(ps.pileA);
	}
	else
		end_prog();
	return (0);
}
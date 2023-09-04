#include "../inc/pushswap.h"

void	end_prog(char *msg, int exit_nb)
{
	ft_printf("%s\n", msg);
	exit(exit_nb);
}

// void	init_piles(t_pA **pA, t_pB **pB, char **av)
// {
// 	// *pA = (t_pA *)malloc(sizeof(t_pA));
// 	// *pB = (t_pB *)malloc(sizeof(t_pB));
// 	// if (!(*pA) || !(*pB))
// 	// 	end_prog("Error", 1);
// 	// (*pA)->nb = 0;
// 	// (pA)->next = NULL;

// }

int	main(int ac, char **av)
{
	// t_pA *pA;
	// t_pB *pB;
	int pA_len;

	if (ac > 1)
	{
		pA_len = check_args(av);
		ft_printf("pA_len = %d\n", pA_len);
		if (!pA_len) // pas de nombre ou erreur
		{
			end_prog("Error", 1);
			return (1);
		}
		else if (pA_len == 1) // un seul nombre deja en ordre
		{
			end_prog("", 0);
			return (0);
		}
		// init_piles(&pA, &pB, av);
		fill_pA(av);
		return (0);
	}
	end_prog("Error", 1);
	return (1);
}
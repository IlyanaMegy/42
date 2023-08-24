#include "../inc/pushswap.h"

int	main(int ac, char **av)
{
	int *pileA;
    int len_pileA;

    pileA = NULL;
    len_pileA = 0;
	if (ac > 1)
		{
            len_pileA = check_args(av);
            if (!len_pileA)
                ft_printf("Error\n");
            pileA = malloc((sizeof(int) * (len_pileA + 1)));
            if (!pileA)
                ft_printf("Error\n");
            // fill_pA(av, &pileA);
        }
	else
		ft_printf("Error\n");
	return (0);
}
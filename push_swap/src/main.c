#include "../inc/pushswap.h"

void	end_prog(void)
{
	ft_printf("Error\n");
	exit(1);
}

int	main(int ac, char **av)
{
	char *pileA;
	char *pileB;
	int len_pileA;

	len_pileA = 0;
	if (ac > 1)
	{
		len_pileA = check_args(av);
		if (!len_pileA)
			end_prog();
		pileA = malloc((sizeof(char) * (len_pileA + 1)));
		pileA[0] = '\0';
		pileB = malloc((sizeof(char) * (len_pileA + 1)));
		pileB[0] = '\0';
		if (!pileB || !pileA)
			end_prog();
		fill_pA(av, &pileA);
		if (!pileA[0] || !pileA)
			end_prog();
        ft_printf("%s\npa\tpb\n", pileA);
		free(pileA);
	}
	else
		end_prog();
	return (0);
}
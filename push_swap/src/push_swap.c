#include "../inc/pushswap.h"

int	in_order(char *pX, int len)
{
	int *int_pX;
	int i;
	int j;

	int_pX = malloc(sizeof(int) * (len + 1));
	int_pX[0] = 0;
	if (!int_pX)
		end_prog();
	i = 0;
	j = 0;
	while (pX[i])
	{
		if (ft_atoi(pX[i]))
		{
			int_pX[j] = ft_atoi(pX[i]);
			j++;
		}
	}
	ft_printf("%s\npa\tpb\nlen = %d\n", *pX);
	return (0);
}
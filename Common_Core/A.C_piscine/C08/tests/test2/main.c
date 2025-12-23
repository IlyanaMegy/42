#include "ft_abs.h"
#include <limits.h>
#include <stdio.h>

int	main(void)
{
	int nb = -INT_MAX;
	printf("abs(%d) = %d\n", nb, ABS(nb));
	return (0);
}
#include <unistd.h>

void	ft_putchar(char c);

void	aff_ligne(int c, char x, char y, char z)
{
	int	i;

	i = 1;
	while (i <= c)
	{
		if (i == 1)
			ft_putchar(x);
		else if (i == c)
			ft_putchar(y);
		else
			ft_putchar(z);
		i++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	if (x > 0 && y > 0)
	{
		aff_ligne(x, 'A', 'A', 'B');
		y--;
		while (y > 1)
		{
			aff_ligne(x, 'B', 'B', ' ');
			y--;
		}
		if (y == 1)
			aff_ligne(x, 'C', 'C', 'B');
	}
}

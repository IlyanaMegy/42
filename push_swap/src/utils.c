#include "../inc/pushswap.h"

void	free_double_char(char **arr_char)
{
	size_t	i;

	i = 0;
	while (arr_char[i])
	{
		free(arr_char[i]);
		i++;
	}
	free(arr_char);
}

void	print_tab(int *tab)
{
	ft_printf("\n-----\ntab :\n-----\n");
	size_t i;

	i = 0;
	while (tab[i])
	{
		ft_printf("%d : %d\n", i, tab[i]);
		i++;
	}
	ft_printf("\n");
}

void	print_double_array(char **a)
{
	int	i;

	i = 0;
	while (a[i])
	{
		ft_printf("\"%s\" ", a[i]);
		i++;
	}
	ft_printf("\n");
}

void	end_n_free(char **array, char *msg, int exit_nb)
{
	free_double_char(array);
	end_prog(msg, exit_nb);
}
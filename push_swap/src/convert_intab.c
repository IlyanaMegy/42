#include "../inc/pushswap.h"

int	nb_nbr(t_ps *ps)
{
	int		nb_nbr;
	char	*s;
	int		i;

	nb_nbr = 0;
	i = 0;
	s = ps->pileA;
	while (s[i])
	{
		if (s[i] && s[i] != '\n')
		{
			nb_nbr++;
			while (s[i] && s[i] != '\n')
				i++;
		}
		i++;
	}
	return (nb_nbr);
}

void	print_tab(int *tab)
{
	ft_printf("tab\n");
	int i;

	i = 0;
	while (tab[i])
	{
		ft_printf("%d : %d\n", i, tab[i]);
		i++;
	}
	ft_printf("\n");
}

int	get_nb(char **tmp, int i, char *pX)
{
	int	j;

	j = 0;
	while (pX[i] && pX[i] != '\n')
	{
		j++;
		i++;
	}
	*tmp = malloc(sizeof(char) * (j));
	if (!(*tmp))
		return (-1);
	i -= j;
	j = 0;
	while (pX[i] && pX[i] != '\n')
	{
		(*tmp)[j] = pX[i];
		i++;
		j++;
	}
	(*tmp)[j] = '\0';
	return (i);
}

int	*int_tab(char *pX, t_ps *ps)
{
	int *int_pX;
	int i;
	char *tmp;
	int j;

	int_pX = malloc(sizeof(int) * (nb_nbr(ps) + 1));
	int_pX[0] = 0;
	if (!int_pX)
		end_prog();
	i = 0;
	j = 0;
	while (pX[i])
	{
		i = get_nb(&tmp, i, pX);
		if (i < 0)
			end_prog();
		int_pX[j] = ft_atoi(tmp);
		j++;
		i++;
		free(tmp);
	}
	// print_tab(int_pX);
	return (int_pX);
}
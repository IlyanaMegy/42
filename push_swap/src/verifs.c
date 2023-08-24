#include "../inc/pushswap.h"

int	pass_spaces(size_t *start, size_t *end, char *s, int *len_pA)
{
	char	*tmp;

	while (*end < ft_strlen(s))
	{
		while (s[*start] == ' ')
			(*start)++;
		*end = *start;
		while (s[*end] != ' ')
			(*end)++;
		tmp = ft_substr(s, *start, *end - *start);
		if (!ft_strlen(tmp))
			break ;
		else if (!ft_atoi(tmp))
			if (!(ft_strlen(tmp) == 1 && tmp[0] == '0'))
				return (1);
		*len_pA += ft_strlen(tmp) + 1;
		*start = *end;
	}
	return (0);
}

int	check_args(char **args)
{
	int		i;
	size_t	start;
	size_t	end;
	int		len_pileA;
	int		err;

	i = 1;
	len_pileA = 0;
	err = 0;
	while (args[i])
	{
		start = 0;
		end = 0;
		err = pass_spaces(&start, &end, args[i], &len_pileA);
		if (err)
			return (0);
		i++;
		len_pileA--;
	}
	ft_printf("len_pA = %d\n", len_pileA);
	return (len_pileA);
}

// void	fill_pA(char **av, int **pA)
// {
// }
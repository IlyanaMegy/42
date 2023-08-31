#include "../inc/pushswap.h"

int	len_incr(size_t *start, size_t *end, char *s, int *len_pA)
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
		free(tmp);
	}
	return (0);
}

int	check_args(char **av)
{
	int		i;
	size_t	start;
	size_t	end;
	int		len_pileA;
	int		err;

	i = 1;
	len_pileA = 0;
	err = 0;
	while (av[i])
	{
		start = 0;
		end = 0;
		err = len_incr(&start, &end, av[i], &len_pileA);
		if (err)
			return (0);
		i++;
		len_pileA--;
	}
	return (len_pileA);
}

char	*get_number(size_t *start, size_t *end, char *s)
{
	char	*tmp;

	while (s[*start] == ' ')
		(*start)++;
	*end = *start;
	while (s[*end] != ' ')
		(*end)++;
	tmp = ft_substr(s, *start, *end - *start);
	if (!ft_strlen(tmp))
		return (NULL);
	else if (!ft_atoi(tmp))
		if (!(ft_strlen(tmp) == 1 && tmp[0] == '0'))
			return (NULL);
	*start = *end;
	return (tmp);
}

void	join_me(char **pA, char *curr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((*pA)[i])
		i++;
	while (curr[j])
	{
		(*pA)[i + j] = curr[j];
		j++;
	}
	if (!(*pA))
		return ;
	if (ft_strlen(*pA) > 1)
	{
		(*pA)[i + j] = '\n';
		(*pA)[i + j + 1] = 0;
	}
	else if (ft_strlen(*pA) == 1)
		(*pA)[0] = 0;
}

int	fill_pA(char **av, char **pA)
{
	int i;
	size_t start;
	size_t end;
	char *res;

	i = 1;
	while (av[i])
	{
		start = 0;
		end = 0;
		while (end < ft_strlen(av[i]))
		{
			res = get_number(&start, &end, av[i]);
			if (ft_strlen(res))
			{
				join_me(pA, res);
				free(res);
			}
		}
		i++;
	}
	if (ft_strlen(*pA) > 1)
		(*pA)[ft_strlen(*pA) - 1] = '\0';
	else if (ft_strlen(*pA) == 1)
		(*pA)[0] = 0;
	return (0);
}
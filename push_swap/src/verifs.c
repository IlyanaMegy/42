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
	int	i;
	int	j;
	int	len;

	i = 1;
	len = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < 48 || av[i][j] > 57)
				return (0);
			j++;
			len++;
		}
		i++;
	}
	return (len);
}

char	*get_number(char *s)
{
	char	*tmp;
	int		j;

	j = 0;
	while (s[j])
		j++;
	tmp = malloc(sizeof(char) * (j + 1));
	if (!tmp)
		return (NULL);
	j = 0;
	while (s[j])
	{
		tmp[j] = s[j];
		j++;
	}
	tmp[j] = '\0';
	if (!ft_strlen(tmp))
		return (NULL);
	else if (!ft_atoi(tmp))
		if (!(ft_strlen(tmp) == 1 && tmp[0] == '0'))
			return (NULL);
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

int	fill_pA(char **av)
{
	int i;
	char *tmp;
	t_pA *pA;

	i = 1;
	// pA = lstnew(0);
	while (av[i])
	{
		tmp = get_number(av[i]);
		if (!tmp)
			return 1;
		ft_printf("tmp = %s\n", tmp);
		lstadd_back(&pA, lstnew(atoi(tmp)));
		free(tmp);
		i++;
	}
	print_list(pA);
	return (0);
}
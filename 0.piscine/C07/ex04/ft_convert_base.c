/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:04:19 by ilymegy           #+#    #+#             */
/*   Updated: 2023/02/23 14:04:21 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int		base_conditions(char *base);
int		in_base(char c, char *base);
int		ft_strlen(char *str);

int	to_int(char *str, char *base, int l_base)
{
	int	res;

	res = 0;
	while (*str && in_base(*str, base) != -1)
	{
		res = res * l_base + (in_base(*str, base));
		str++;
	}
	return (res);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	base_len;

	sign = 1;
	while (*str == 32 || (*str >= '\t' && *str <= '\r'))
		++str;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	base_len = ft_strlen(base);
	return ((to_int(str, base, base_len) * sign));
}

int	try(int nbr, char *base)
{
	int	l_base;
	int	i;

	i = 0;
	l_base = ft_strlen(base);
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		i++;
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		nbr = nbr / l_base;
		i++;
	}
	return (i + 1);
}

void	ft_putnbr_base(int n, char *base, char *res)
{
	int	l_base;
	int	i;

	l_base = ft_strlen(base);
	i = try(n, base);
	res[--i] = '\0';
	if (n == 0)
		res[0] = base[0];
	if (n < 0)
	{
		res[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		res[--i] = base[n % l_base];
		n = n / l_base;
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*str_end;
	int		len_end;

	if (!base_conditions(base_from) || !base_conditions(base_to))
		return (NULL);
	len_end = try(ft_atoi_base(nbr, base_from), base_to);
	str_end = malloc((len_end + 1) * sizeof(char));
	if (!str_end)
		return (NULL);
	ft_putnbr_base(ft_atoi_base(nbr, base_from), base_to, str_end);
	str_end[len_end] = '\0';
	return (str_end);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:40:21 by ilymegy           #+#    #+#             */
/*   Updated: 2023/02/16 17:40:24 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	base_conditions(char *base)
{
	int	i;
	int	n;

	i = 0;
	while (base[i])
	{
		if (base[i] == 32 || (base[i] >= '\t' && base[i] <= '\r'))
			return (0);
		if (base[i] == 43 || base[i] == 45)
			return (0);
		n = i + 1;
		while (base[n])
		{
			if (base[n] == base[i])
				return (0);
			++n;
		}
		++i;
	}
	if (i < 2)
		return (0);
	return (1);
}

int	in_base(char c, char *base)
{
	while (*base)
	{
		if (*base == c)
			return (1);
		base++;
	}
	return (0);
}

int	get_int_of_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
		{
			return (i);
		}
		i++;
	}
	return (i);
}

int	to_int(char *str, char *base, int l_base)
{
	int	res;

	res = 0;
	while (*str && in_base(*str, base))
	{
		res *= l_base;
		res += get_int_of_base(*str, base);
		str++;
	}
	return (res);
}

int	ft_atoi_base(char *str, char *base)
{
	int	res;
	int	sign;
	int	base_len;

	res = 0;
	sign = 1;
	if (base_conditions(base))
	{
		while (*str == 32 || (*str >= '\t' && *str <= '\r'))
			++str;
		while (*str == '-' || *str == '+')
		{
			if (*str == '-')
				sign *= -1;
			str++;
		}
		base_len = 0;
		while (base[base_len])
			base_len++;
		res = to_int(str, base, base_len);
	}
	return (res * sign);
}

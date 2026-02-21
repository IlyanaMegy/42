/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 21:34:51 by ilymegy           #+#    #+#             */
/*   Updated: 2023/02/14 21:35:12 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	at_first(char *str, int i)
{
	while (str[i])
	{
		if (!(str[i + 1] >= 48 && str[i + 1] <= 57))
			if (!(str[i] >= 9 && str[i] <= 13) || str[i] == 32)
				if ((str[i] != 43) || (str[i] != 32))
					return (0);
		++i;
	}
	return (1);
}

int	white_here(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	pow_this(int x)
{
	int	res;

	res = 1;
	while (x)
	{
		res *= 10;
		--x;
	}
	return (res);
}

int	end_it_at(char *str, int i, int minus)
{
	int	start;
	int	occur;
	int	res;

	start = i;
	while (str[i])
	{
		if (!(str[i + 1] >= 48 && str[i + 1] <= 57))
			break ;
		++i;
	}
	res = 0;
	occur = i - start;
	while (start <= i)
	{
		res += ((str[start]) - 48) * pow_this(occur);
		--occur;
		start++;
	}
	while (minus > 0)
	{
		res = -res;
		--minus;
	}
	return (res);
}

int	ft_atoi(char *str)
{
	int	i;
	int	minus;
	int	res;

	i = 0;
	if (str && !(at_first(str, i)))
	{
		minus = 0;
		while (white_here(str[i]))
			++i;
		while (str[i] == 43 || str[i] == 45)
		{
			if (str[i] == 45)
				++minus;
			++i;
		}
		if ((minus > 0) && white_here(str[i]))
			return (0);
		if (str[i] >= 48 && str[i] <= 57)
			res = end_it_at(str, i, minus);
		return (res);
	}
	return (0);
}

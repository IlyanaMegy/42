/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:56:03 by ilymegy           #+#    #+#             */
/*   Updated: 2023/05/16 15:56:08 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	int_len(int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

char	*p_nbr(int nbr)
{
	long	n;
	int		len;
	char	*res;

	n = nbr;
	len = int_len(n) + 1;
	if (n < 0)
	{
		res = (char *)malloc(sizeof(char) * (len + 1));
		res[0] = '-';
		res[len] = '\0';
		n = -n;
	}
	else
	{
		res = (char *)malloc(sizeof(char) * (len));
		res[len] = '\0';
		if (n == 0)
			res[0] = 0 + 48;
	}
	while (n > 0)
	{
		res[--len] = n % 10 + 48;
		n = n / 10;
	}
	return (res);
}

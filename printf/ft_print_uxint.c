/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uxint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:56:55 by ilymegy           #+#    #+#             */
/*   Updated: 2023/05/16 15:57:05 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	uint_len(unsigned int num, int base)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / base;
	}
	return (len);
}

char	*what_base(char format)
{
	char	*base_10;
	char	*base_16;
	char	*BASE_16;

	base_10 = "0123456789";
	base_16 = "0123456789abcdef";
	BASE_16 = "0123456789ABCDEF";
	if (format == 'u')
		return (base_10);
	else if (format == 'x')
		return (base_16);
	return (BASE_16);
}

char	*p_uint(unsigned int n, char format)
{
	int				len;
	char			*res;
	unsigned int	l_base;
	char			*base;

	base = what_base(format);
	l_base = ft_strlen(base);
	len = uint_len(n, l_base);
	res = (char *)malloc(sizeof(char) * (len + 1));
	res[len] = '\0';
	if (n == 0)
		res[0] = base[0];
	while (n >= l_base)
	{
		res[--len] = base[n % l_base];
		n = n / l_base;
	}
	res[--len] = base[n % l_base];
	return (res);
}

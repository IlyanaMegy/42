/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltorkia <ltorkia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 03:27:14 by ltorkia           #+#    #+#             */
/*   Updated: 2023/05/10 03:27:14 by ltorkia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdlib.h>*/

static size_t	ft_count_nb(int n)
{
	size_t			count;
	unsigned int	nb;

	count = 0;
	nb = n;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		nb = -n;
		count++;
	}
	while (nb > 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	nb;
	size_t			len;

	nb = n;
	len = ft_count_nb(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		nb = -n;
	str[len] = '\0';
	if (n < 0)
		str[0] = '-';
	len--;
	while (nb > 0)
	{
		str[len] = nb % 10 + '0';
		nb /= 10;
		len--;
	}
	return (str);
}

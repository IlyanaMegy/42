/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 10:59:54 by ilymegy           #+#    #+#             */
/*   Updated: 2023/02/16 10:59:55 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	conditions(char *base)
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

void	ft_putnbr_base(int nbr, char *base)
{
	int		l_base;
	long	n;

	l_base = 0;
	n = nbr;
	while (base[l_base])
		l_base++;
	if (conditions(base))
	{
		if (n < 0)
		{
			ft_putchar('-');
			n = -n;
		}
		if (n < l_base)
			ft_putchar(base[n]);
		if (n >= l_base)
		{
			ft_putnbr_base(n / l_base, base);
			ft_putnbr_base(n % l_base, base);
		}
	}
}

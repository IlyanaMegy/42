/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltorkia <ltorkia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:09:57 by ltorkia           #+#    #+#             */
/*   Updated: 2023/05/26 17:02:01 by ltorkia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print(unsigned int n)
{
	unsigned int	nb;

	nb = n;
	if (nb > 9)
		ft_print(n / 10);
	if (nb <= 9)
	{
		ft_putchar_fd(nb + '0', 1);
		return ;
	}
	ft_putchar_fd((nb % 10) + '0', 1);
}

int	ft_print_unsigned(unsigned int n)
{
	unsigned int	i;

	ft_print(n);
	i = 1;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

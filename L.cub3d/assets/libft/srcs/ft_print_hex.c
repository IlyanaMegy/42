/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltorkia <ltorkia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:09:39 by ltorkia           #+#    #+#             */
/*   Updated: 2023/05/26 17:01:40 by ltorkia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_hex_len(unsigned int val)
{
	int				i;

	i = 0;
	while (val)
	{
		val = val / 16;
		i++;
	}
	return (i);
}

static void	ft_print(unsigned int val, int ascii)
{
	if (val >= 16)
	{
		ft_print(val / 16, ascii);
		ft_print(val % 16, ascii);
	}
	else
	{
		if (val <= 9)
			ft_putchar_fd((val + '0'), 1);
		else
			ft_putchar_fd((val + ascii), 1);
	}
}

int	ft_print_hex(unsigned int val, int ascii)
{
	int	i;

	i = 0;
	if (!val)
		i += ft_print_char('0');
	else
	{
		ft_print(val, ascii);
		i += ft_hex_len(val);
	}
	return (i);
}

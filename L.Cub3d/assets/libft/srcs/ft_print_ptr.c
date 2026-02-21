/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltorkia <ltorkia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:09:48 by ltorkia           #+#    #+#             */
/*   Updated: 2023/05/26 17:01:49 by ltorkia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ptr_len(unsigned long val)
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

static void	ft_print(unsigned long val)
{
	if (val >= 16)
	{
		ft_print(val / 16);
		ft_print(val % 16);
	}
	else
	{
		if (val <= 9)
			ft_putchar_fd((val + '0'), 1);
		else
			ft_putchar_fd((val - 10 + 'a'), 1);
	}
}

int	ft_print_ptr(unsigned long val)
{
	int	i;

	i = 0;
	if (!val)
		i += ft_print_str("(nil)");
	else
	{
		i += ft_print_str("0x");
		ft_print(val);
		i += ft_ptr_len(val);
	}
	return (i);
}

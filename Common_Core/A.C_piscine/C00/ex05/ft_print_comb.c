/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:11:06 by ilymegy           #+#    #+#             */
/*   Updated: 2023/02/09 20:34:25 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_them_pls(char a, char  b, char c)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
	if (!(a == '7' && b == '8' && c == '9'))
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	char	a;
	char	b;
	char	c;

	a = '0';
	while (a <= '7')
	{
		b = a;
		while (b <= '8')
		{
			c = b;
			while (c <= '9')
			{
				if (a != b && b != c && c != a)
					print_them_pls(a, b, c);
				++c;
			}
			++b;
		}
		++a;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:53:27 by aducobu           #+#    #+#             */
/*   Updated: 2023/02/11 15:00:02 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	aff_ligne(int c, char x, char y)
{
	int	i;

	i = 1;
	while (i <= c)
	{
		if (i == 1)
			ft_putchar(x);
		else if (i == c)
			ft_putchar(y);
		else
			ft_putchar('-');
		i++;
	}
}

void	rush(int x, int y)
{
	int	i;
	int	j;

	if (x > 0 && y > 0)
	{
		j = 1;
		aff_ligne(x, 'o', 'o');
		ft_putchar('\n');
		while (j <= y - 2)
		{
			i = 1;
			while (i <= x)
			{
				if (i == 1 || i == x)
					ft_putchar('|');
				else
					ft_putchar(' ');
				i++;
			}
			ft_putchar('\n');
			j++;
		}
		if (y >= 2)
			aff_ligne(x, 'o', 'o');
	}
}

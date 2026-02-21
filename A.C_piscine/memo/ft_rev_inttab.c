/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:00:56 by ilymegy           #+#    #+#             */
/*   Updated: 2023/02/11 11:26:42 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	n;
	int	i;
	int	temp;

	printf("here we goo !\n");
	printf("size = %d , tab[2] = %d\n", size, tab[2]);
	i = 0;
	n = size - 1;
	printf("n = %d\n", n);
	while (n >= 0)
	{
		printf("tab[%d] = %d.\n", n, tab[n]);
		--n;
	}
	n = size - 1;
	printf("-------------------------------------\n");
	printf("			 REVERSE		             \n");
	printf("even\n");
	printf("n = %d\n", n);
	printf("size = %d\n", size);
	while (n >= (size / 2))
	{
		temp = tab[i];
		tab[i] = tab[n];
		tab[n] = temp;
		printf("tab[%d] = %d, tab[%d] = %d\n", i, tab[i], n, tab[n]);
		--n;
		++i;
	}
	printf("-------------------------------------\n");
	printf("                  RES                \n");
	n = 0;
	while (n <= size)
	{
		printf("tab[%d] = %d.\n", n, tab[n]);
		++n;
	}
}

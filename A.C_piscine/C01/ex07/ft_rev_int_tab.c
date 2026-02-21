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

	i = 0;
	n = size - 1;
	if (size > 0)
	{
		while (n >= (size / 2))
		{
			temp = tab[i];
			tab[i] = tab[n];
			tab[n] = temp;
			--n;
			++i;
		}
	}
}

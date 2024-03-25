/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:57:35 by ilymegy           #+#    #+#             */
/*   Updated: 2023/02/19 21:44:47 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_char(int nb)
{
	char	c;

	c = nb + 48;
	write(1, &c, 1);
}

void	g_aff_table(void)
{
	int	g_pos_lin;

	g_pos_lin = 0;
	while (g_pos_lin < 16)
	{
		print_char(g_table[g_pos_lin]);
		if (g_pos_lin % 4 != 3)
			write(1, " ", 1);
		++g_pos_lin;
		if (g_pos_lin % 4 == 0)
			write(1, "\n", 1);
	}
}

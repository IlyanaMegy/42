/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:09:13 by rmorice           #+#    #+#             */
/*   Updated: 2023/02/19 21:44:07 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	reset_height(int *p_pos)
{
	g_table[*p_pos] = 0;
	*p_pos = *p_pos - 1;
	g_table[*p_pos]++;
	if (g_table[*p_pos] == 5)
		*p_pos = reset_height(p_pos);
	return (*p_pos);
}

int	determine_height(int *p_pos)
{
	int	height;

	height = 1;
	while (g_table[0] != 0)
	{
		g_table[*p_pos] = height;
		if ((check_height_neighbors(*p_pos) == 1)
			&& (check_height_clues(*p_pos) > 0))
		{
			*p_pos = *p_pos + 1;
			if ((*p_pos == 16) && (check_full_height() == 1))
			{
				g_aff_table();
				return (1);
			}
			else
				height = 0;
		}
		height++;
		if (height == 5)
			height = g_table[reset_height(p_pos)];
	}
	return (0);
}

int	resolve_towerdoku(void)
{
	int	pos;
	int	*p_pos;

	pos = 1;
	p_pos = &pos;
	g_table[0] = 1;
	return (determine_height(p_pos));
}

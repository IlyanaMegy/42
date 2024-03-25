/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_up_down_left_right.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:56:56 by rmorice           #+#    #+#             */
/*   Updated: 2023/02/19 17:57:40 by rmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	compt_up(int pos)
{
	int	comp;
	int	max;
	int	i;

	comp = 0;
	max = 0;
	i = pos % 4;
	if (g_table[i] == 0)
		return (1);
	while (i <= pos)
	{
		if (g_table[i] > max)
		{
			max = g_table[i];
			comp++;
		}
		i += 4;
	}
	if (comp > g_clues_list[pos % 4])
		return (0);
	if (comp == g_clues_list[pos % 4])
		return (2);
	return (1);
}

int	compt_down(int pos)
{
	int	comp;
	int	max;
	int	i;
	int	l;

	comp = 0;
	max = 0;
	l = 16;
	i = l - 4 + pos % 4;
	if (g_table[i] == 0)
		return (1);
	while (i >= pos)
	{
		if (g_table[i] > max)
		{
			max = g_table[i];
			comp++;
		}
		i -= 4;
	}
	if (comp > g_clues_list[4 + pos % 4])
		return (0);
	if (comp == g_clues_list[4 + pos % 4])
		return (2);
	return (1);
}

int	compt_left(int pos)
{
	int	comp;
	int	max;
	int	i;

	comp = 0;
	max = 0;
	i = pos - pos % 4;
	if (g_table[i] == 0)
		return (1);
	while (i <= pos)
	{
		if (g_table[i] > max)
		{
			max = g_table[i];
			comp++;
		}
		i++;
	}
	if (comp > g_clues_list[8 + pos / 4])
		return (0);
	if (comp == g_clues_list[8 + pos / 4])
		return (2);
	return (1);
}

int	compt_right(int pos)
{
	int	comp;
	int	max;
	int	i;

	comp = 0;
	max = 0;
	i = pos + (3 - pos % 4);
	if (g_table[i] == 0)
		return (1);
	while (i >= pos)
	{
		if (g_table[i] > max)
		{
			max = g_table[i];
			comp++;
		}
		i--;
	}
	if (comp > g_clues_list[12 + pos / 4])
		return (0);
	if (comp == g_clues_list[12 + pos / 4])
		return (2);
	return (1);
}

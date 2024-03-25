/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:56:24 by rmorice           #+#    #+#             */
/*   Updated: 2023/02/19 21:59:43 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_height_neighbors(int pos)
{
	int	i;
	int	end_row;
	int	end_board;

	i = pos - pos % 4;
	end_row = pos - pos % 4 + 4;
	while (i < end_row)
	{
		if ((pos != i) && (g_table[pos] == g_table[i]))
			return (0);
		i++;
	}
	i = pos % 4;
	end_board = 16;
	while (i < end_board)
	{
		if ((pos != i) && (g_table[pos] == g_table[i]))
			return (0);
		i += 4;
	}
	return (1);
}

int	check_height_clues(int pos)
{
	if ((compt_up(pos) > 0) && (compt_down(pos) > 0) && (compt_left(pos) > 0)
		&& (compt_right(pos) > 0))
		return (1);
	return (0);
}

int	check_full_height(void)
{
	int	pos_ud;
	int	pos_lr;
	int	check;

	pos_ud = 0;
	pos_lr = 0;
	check = 0;
	while ((pos_ud < 4) && (pos_lr < 16))
	{
		if ((compt_up(12 + pos_ud) == 2) && (compt_down(pos_ud) == 2)
			&& ((compt_left(3 + pos_lr) == 2) && (compt_right(pos_lr) == 2)))
			check++;
		pos_ud++;
		pos_lr += 4;
	}
	if (check == 4)
		return (1);
	return (0);
}

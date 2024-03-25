/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:56:57 by ilymegy           #+#    #+#             */
/*   Updated: 2023/02/19 21:43:38 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	*g_table;
int	*g_clues_list;

void	fill_list(int *list)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		list[i] = 0;
		++i;
	}
}

int	main(int argc, char *argv[])
{
	g_clues_list = (int *)malloc(sizeof(int *) * 16);
	g_table = (int *)malloc(sizeof(int *) * 16);
	if (!(g_check_entry(argc, argv[1])))
	{
		fill_list(g_clues_list);
		fill_list(g_table);
		write(1, "Error\n", 6);
	}
	else
	{
		g_convert_to_array(argv[1]);
		fill_list(g_table);
	}
	if (resolve_towerdoku() == 1)
	{
		free(g_clues_list);
		free(g_table);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:57:19 by ilymegy           #+#    #+#             */
/*   Updated: 2023/02/19 21:42:38 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	g_len_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

int	g_check_entry(int argc, char *str)
{
	int	i;
	int	compt_nb;

	if (argc == 2 && g_len_str(str) == 31)
	{
		i = 0;
		compt_nb = 0;
		while (str[i])
		{
			if (!((str[i] >= 49 && str[i] <= 52) || str[i] == 32))
				return (0);
			if ((str[i] >= 49 && str[i] <= 52))
				++compt_nb;
			++i;
		}
		if (compt_nb != 16)
			return (0);
		return (1);
	}
	return (0);
}

void	g_convert_to_array(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] >= 49 && str[i] <= 52)
		{
			g_clues_list[j] = str[i] - 48;
			++j;
		}
		++i;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:29:56 by ilymegy           #+#    #+#             */
/*   Updated: 2023/05/18 12:30:02 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	search_str(const char *string, int searchedChar)
{
	int	i;

	if (!searchedChar)
		return (-1);
	i = 0;
	while (string[i])
	{		
		if (string[i] == ((unsigned char)searchedChar))
			return (i);
		i++;
	}
	return (-1);
}

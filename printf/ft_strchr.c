/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:57:27 by ilymegy           #+#    #+#             */
/*   Updated: 2023/05/16 15:57:30 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_strchr(const char *string, int searchedChar)
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

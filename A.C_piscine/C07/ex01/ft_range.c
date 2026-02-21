/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:10:57 by ilymegy           #+#    #+#             */
/*   Updated: 2023/02/22 15:10:59 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*ptr;
	int	str_len;
	int	i;

	str_len = max - min;
	if (min >= max)
		return (NULL);
	ptr = malloc((str_len) * sizeof(int));
	if (ptr)
	{
		i = 0;
		while (i < str_len)
		{
			ptr[i] = (min + i);
			i++;
		}
		return (ptr);
	}
	return (NULL);
}

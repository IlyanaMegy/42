/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:40:50 by ilymegy           #+#    #+#             */
/*   Updated: 2023/02/13 20:40:53 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../mandatory/inc/libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	if (s1[i] && s2[i])
	{
		while (s1[i] && s2[i])
		{
			if (s1[i] - s2[i])
				return (s1[i] - s2[i]);
			++i;
		}
		return (s1[i] - s2[i]);
	}
	return (s1[i] - s2[i]);
}

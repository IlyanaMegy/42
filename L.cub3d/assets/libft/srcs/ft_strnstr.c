/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltorkia <ltorkia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 12:23:08 by ltorkia           #+#    #+#             */
/*   Updated: 2023/05/06 12:23:08 by ltorkia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	if ((!big || !little) && len == 0)
		return (0);
	str = (char *)big;
	i = 0;
	if (!little[i])
		return (str);
	while (str[i] && i < len)
	{
		j = 0;
		while (str[i + j] == little[j] && (i + j) < len)
		{
			if (!little[j + 1])
				return (&str[i]);
			j++;
		}
		i++;
	}
	return (0);
}

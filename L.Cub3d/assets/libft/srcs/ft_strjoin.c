/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltorkia <ltorkia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:23:47 by ltorkia           #+#    #+#             */
/*   Updated: 2023/05/19 12:09:25 by ltorkia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		len1;
	int		i;

	if (!s1 || !s2)
		return (0);
	len1 = ft_strlen((char *)s1);
	dest = (char *)malloc(sizeof(char) * (len1 + ft_strlen((char *)s2) + 1));
	if (!dest)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		dest[len1] = s2[i];
		len1++;
		i++;
	}
	dest[len1] = '\0';
	return (dest);
}

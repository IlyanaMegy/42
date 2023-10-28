/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeaude <pabeaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:36:22 by pabeaude          #+#    #+#             */
/*   Updated: 2022/11/30 14:03:45 by pabeaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	if (size <= ft_strlen(dst))
		return (size + ft_strlen(src));
	len = ft_strlen(dst);
	i = 0;
	while (src[i] != '\0' && len + 1 < size)
	{
		dst[len] = src[i];
		len++;
		i++;
	}
	dst[len] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[i]));
}
/*
#include <stdio.h>
int	main()
{
	unsigned int	nb = 17;
	char dest[50] = "This is ";
	char src[50] = "a potentially long string";

	ft_strlcat(dest, src, nb);

	printf("%s", dest);
	return(0);
}
*/
// while (src[i] && ((sd + i) < nb))
// while (src[i] && ( i < sd))

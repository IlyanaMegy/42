/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:01:04 by ilymegy           #+#    #+#             */
/*   Updated: 2023/05/02 13:01:08 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	int		x;
	size_t	len_dest;
	size_t	len_src;

	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	if (size)
	{
		if (size < len_dest)
			len_src += size;
		else
			len_src += len_dest;
		x = 0;
		while (src[x] && (len_dest + x) < size - 1)
		{
			dest[len_dest + x] = src[x];
			++x;
		}
		dest[len_dest + x] = '\0';
		return (len_src);
	}
	return (len_src);
}

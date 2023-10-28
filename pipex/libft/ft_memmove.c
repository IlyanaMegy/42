/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeaude <pabeaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:42:27 by pabeaude          #+#    #+#             */
/*   Updated: 2022/11/30 12:22:35 by pabeaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*dest2;
	char	*src2;

	i = 0;
	dest2 = (char *)dest;
	src2 = (char *)src;
	if (!dest2 && !src2)
		return (NULL);
	if (dest < src)
	{
		while (i < n)
		{
		dest2[i] = src2[i];
		i++;
		}
	}
	else
	{
		while (n--)
			dest2[n] = src2[n];
	}
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeaude <pabeaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:19:26 by pabeaude          #+#    #+#             */
/*   Updated: 2022/12/06 16:25:54 by pabeaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*dest2;
	char	*src2;

	i = 0;
	if (!dest && !src)
		return (NULL);
	dest2 = (char *)dest;
	src2 = (char *)src;
	while (i < n)
	{
		dest2[i] = src2[i];
		i++;
	}
	return (dest);
}
/*
int    main(void)
{
	char	src[] = "Hello";
	char	dest[] = "Bonjour";

	printf("%s\n", src);
	printf("%s\n", dest);
	printf("\n");
	printf("%s\n", (char *)memcpy(dest, src, 3));
	printf("%s\n", (char *)ft_memcpy(dest, src, 3));
	printf("\n");
	printf("%s\n", src);
	printf("%s\n", dest);
}
*/

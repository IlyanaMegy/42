/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:00:49 by ilymegy           #+#    #+#             */
/*   Updated: 2023/05/02 13:00:52 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	src_len;
	char	*pnt;

	if (!src)
		return (NULL);
	src_len = ft_strlen(src) + 1;
	pnt = (char *)malloc(src_len * sizeof(char));
	if (!pnt)
		return (NULL);
	return ((char *)ft_memcpy(pnt, src, src_len));
}

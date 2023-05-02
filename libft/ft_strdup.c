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

char	*ft_strdup(char *src)
{
	int		src_len;
	char	*pnt;
	int		i;

	src_len = ft_strlen(src);
	pnt = (char *)malloc((src_len + 1) * sizeof(char));
	if (!pnt)
		return (NULL);
	i = 0;
	while (src[i])
	{
		pnt[i] = src[i];
		i++;
	}
	pnt[i] = '\0';
	return (pnt);
}

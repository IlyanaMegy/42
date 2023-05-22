/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:59:13 by ilymegy           #+#    #+#             */
/*   Updated: 2023/05/17 10:59:17 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	n;

	n = 0;
	while (str[n])
		++n;
	return (n);
}

long	ft_strchr(const char *string, int searchedChar)
{
	long	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == ((unsigned char)searchedChar))
			return (i);
		i++;
	}
	if (string[i] == ((unsigned char)searchedChar))
		return (i);
	return (-1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	l;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		new = malloc(sizeof(char));
		new[0] = 0;
		if (!new)
			return (NULL);
	}
	else
	{
		l = ft_strlen(s + start);
		if (!(l < len))
			l = len;
		new = (char *)malloc((l + 1) * sizeof(char));
		if (!new)
			return (NULL);
		new[l] = 0;
		while (l-- > 0)
			new[l] = s[start + l];
	}
	return (new);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	len;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcpy((str + ft_strlen(s1)), s2, ft_strlen(s2) + 1);
	free(s1);
	return (str);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (src[i] && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (ft_strlen(src));
}

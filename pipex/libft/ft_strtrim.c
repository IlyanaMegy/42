/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeaude <pabeaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:32:18 by pabeaude          #+#    #+#             */
/*   Updated: 2022/11/30 10:06:00 by pabeaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	int		i;
	int		deb;
	int		fin;

	i = 0;
	deb = 0;
	fin = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[deb] && ft_strchr(set, s1[deb]) != NULL)
		deb++;
	fin = ft_strlen(s1);
	while (deb < fin && ft_strchr(set, s1[fin - 1]) != NULL)
		fin--;
	dest = malloc((fin - deb) * sizeof(char) + 1);
	if (!dest)
		return (NULL);
	while (deb < fin)
		dest[i++] = s1[deb++];
	dest[i] = '\0';
	return (dest);
}

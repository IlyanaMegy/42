/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 19:55:25 by ilymegy           #+#    #+#             */
/*   Updated: 2023/02/27 19:55:27 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	words_count(char *s, char sep)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == sep)
			++s;
		if (*s)
			++count;
		while (*s && *s != sep)
			++s;
	}
	return (count);
}

static void	give_to(char **tab, char const *s, char sep)
{
	char		**res;
	char const	*tmp;

	tmp = s;
	res = tab;
	while (*tmp)
	{
		while (*s == sep)						// pass sep in *s
			++s;
		tmp = s;								// update *tmp pointer to *s
		while (*tmp && *tmp != sep)				// increment *tmp pointer
			++tmp;
		if (*tmp == sep || tmp > s)				// if sep again or if end of *s
		{
			*res = ft_substr(s, 0, tmp - s);	// add passed word to res
			s = tmp;							// update *s pointer at *tmp position
			++res;								// get to next res block
		}
	}
	*res = NULL;
}

char	**ft_split(char const *s, char sep)
{
	char	**res;

	if (!s)
		return (NULL);
	res = (char **)malloc((words_count((char *)s, sep) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	give_to(res, s, sep);
	return (res);
}

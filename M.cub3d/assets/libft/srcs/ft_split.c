/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltorkia <ltorkia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 00:51:27 by ltorkia           #+#    #+#             */
/*   Updated: 2023/05/19 12:08:54 by ltorkia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if ((i == 0 && s[i] != c)
			|| (s[i] == c && s[i + 1] != '\0' && s[i + 1] != c))
			count++;
		i++;
	}
	return (count);
}

static char	**set_free(char **s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (0);
}

static char	**ft_splitter(char **words, char const *s, char c)
{
	size_t	next;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] && j < ft_count_words(s, c))
	{
		if (s[i] != c)
		{
			next = i + 1;
			while (s[next] && s[next] != c)
				next++;
			words[j] = ft_substr(s, i, next - i);
			if (!words[j])
				return (set_free(words));
			j++;
			i = next;
		}
		else
			i++;
	}
	words[j] = 0;
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**words;

	if (!s)
		return (0);
	words = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!words)
		return (0);
	return (ft_splitter(words, s, c));
}

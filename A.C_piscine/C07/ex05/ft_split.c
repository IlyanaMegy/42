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
#include <stdlib.h>

int	in_sep(char c, char *sep)
{
	while (*sep)
	{
		if (c == *sep)
			return (1);
		sep++;
	}
	return (0);
}

int	words_count(char *str, char *charset)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (in_sep(str[i], charset))
			i++;
		if (str[i] && !in_sep(str[i], charset))
		{
			count++;
			while (str[i] && !in_sep(str[i], charset))
				i++;
		}
		i++;
	}
	return (count);
}

char	*word(char *str, int at, char *charset)
{
	int		i;
	int		j;
	char	*word;

	i = at;
	j = 0;
	while (str[i] && !in_sep(str[i], charset))
	{
		j++;
		i++;
	}
	word = (char *)malloc(j * sizeof(char) + 1);
	if (!word)
		return (NULL);
	i = at;
	j = 0;
	while (str[i] && !in_sep(str[i], charset))
	{
		word[j] = str[i];
		i++;
		j++;
	}
	word[j] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		i;
	int		j;

	res = NULL;
	res = (char **)malloc(words_count(str, charset) * sizeof(char *) + 1);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (in_sep(str[i], charset))
			i++;
		if (!in_sep(str[i], charset) && str[i])
		{
			res[j] = word(str, i, charset);
			j++;
			while (str[i] && !in_sep(str[i], charset))
				i++;
		}
	}
	res[j] = NULL;
	return (res);
}

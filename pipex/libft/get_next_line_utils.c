/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeaude <pabeaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 09:03:53 by pabeaude          #+#    #+#             */
/*   Updated: 2023/09/21 12:39:56 by pabeaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	gnl_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	gnl_strrchr(char *s, int c)
{
	int	len;

	len = gnl_strlen(s);
	while (len >= 0)
	{
		if (s[len] == (char)c)
			return (1);
		else
			len--;
	}
	return (0);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*s3;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!s1 && !s2)
		return (NULL);
	s3 = malloc(sizeof(char) * (gnl_strlen(s1) + gnl_strlen(s2) + 1));
	if (!s3)
		return (NULL);
	while (s1 && s1[++j])
		s3[++i] = s1[j];
	j = -1;
	while (s2 && s2[++j])
		s3[++i] = s2[j];
	s3[++i] = '\0';
	if (s1)
		free(s1);
	return (s3);
}

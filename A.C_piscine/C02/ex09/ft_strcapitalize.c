/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:29:27 by ilymegy           #+#    #+#             */
/*   Updated: 2023/02/12 13:29:30 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	is_low_letter(char c)
{
	return ((c >= 97 && c <= 122));
}

int	is_letter(char c)
{
	return (((c >= 97 && c <= 122) || (c >= 65 && c <= 90)));
}

int	is_num(char c)
{
	return ((c >= 48 && c <= 57));
}

int	is_alphanum(char c)
{
	return (is_letter(c) || is_num(c));
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((is_low_letter(str[i])) && (!(is_alphanum(str[i - 1]))))
			str[i] -= 32;
		else if ((str[i] >= 65 && str[i] <= 90) && (is_alphanum(str[i - 1])))
			str[i] += 32;
		i++;
	}
	return (str);
}

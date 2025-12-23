/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltorkia <ltorkia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:23:47 by ltorkia           #+#    #+#             */
/*   Updated: 2024/05/17 18:35:11 by ltorkia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

/// @brief cut '\n' at the end of a string (replace by '\0')
/// @param s: string
void	cut_linebreak(char *s)
{
	int		last_index;

	if (ft_strlen(s) > 0)
	{
		last_index = ft_strlen(s) - 1;
		if (s[last_index] == '\n')
			s[last_index] = '\0';
	}
	return ;
}

/// @brief check if the string contains only whitespaces
/// @param s: string
/// @return true if only whitespaces, false otherwise
bool	check_whitespace(char *s)
{
	int	i;

	i = -1;
	while (s[i++])
		if (ft_isspace(s[i]) || s[i] == '\t')
			return (false);
	return (true);
}

/// @brief trim spaces at the end of the string (for texture paths / rgb)
/// @param s: string
/// @return new length
int	trim_end_spaces(char *s)
{
	int		i;

	i = ft_strlen(s) - 1;
	while (i >= 0 && ft_isspace(s[i]))
	{
		s[i] = '\0';
		i--;
	}
	return (ft_strlen(s));
}

/// @brief check commas for rgb color validity
/// @param s: string to check
/// @return true if valid, false otherwise
bool	check_commas(char *s)
{
	int	i;
	int	comma;

	i = 0;
	comma = 0;
	while (s[i])
	{
		if (s[i] == ',')
			comma++;
		i++;
	}
	if (comma != 2)
		return (false);
	return (true);
}

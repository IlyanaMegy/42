/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_infos_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltorkia <ltorkia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:23:47 by ltorkia           #+#    #+#             */
/*   Updated: 2024/06/26 17:41:02 by ltorkia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

/// @brief skip to index start of txt path or rgb data + save index end str (i)
///			--if there is not at least one space before the path, return 0
/// @param s: string to check
/// @param i: index
/// @return index start
static int	skip_to_path(char *s, int *i)
{
	int	start;

	start = 0;
	if (s[(*i)] && !ft_isspace(s[(*i)]))
		return (0);
	while (s[(*i)] && ft_isspace(s[(*i)]))
		(*i)++;
	if (s[(*i)] && s[(*i)] == '\t')
		return (0);
	start = (*i);
	while (s[(*i)] && s[(*i)] != '\n')
		(*i)++;
	return (start);
}

/// @brief get char rgb tab len
///			--check if each char is a digit
///			--check if each char len is <= 3
///			--check if tab len == 3
/// @param tab: tab
/// @return len
static int	get_tab_len(char **tab)
{
	int	len;
	int	i;

	len = 0;
	while (tab[len])
	{
		i = 0;
		while (tab[len][i])
		{
			if (!ft_isdigit(tab[len][i])
				|| (tab[len][0] == '0' && tab[len][1]))
				return (0);
			i++;
		}
		if (i > 3)
			return (0);
		len++;
	}
	if (len != 3)
		return (0);
	return (len);
}

/// @brief convert char *rgb to int *rgb
///			--check if each number is between 0 and 255
/// @param s: string to convert
/// @param len: len
/// @return rgb ptr
static int	*convert_rgb(char *s, int len)
{
	char	**rgb_tab_char;
	int		*rgb_tab;

	if (!check_commas(s))
		return (NULL);
	rgb_tab_char = ft_split(s, ',');
	if (!rgb_tab_char)
		return (0);
	len = get_tab_len(rgb_tab_char);
	if (!len)
		return (free_tab((void **)rgb_tab_char), NULL);
	rgb_tab = (int *)malloc(sizeof(int) * len);
	if (!rgb_tab)
		return (free_tab((void **)rgb_tab_char), NULL);
	len = 0;
	while (rgb_tab_char[len])
	{
		rgb_tab[len] = ft_atoi(rgb_tab_char[len]);
		if (rgb_tab[len] < 0 || rgb_tab[len] > 255)
			return (free_tab((void **)rgb_tab_char), free_ptr(rgb_tab), NULL);
		len++;
	}
	if (len != 3)
		return (free_tab((void **)rgb_tab_char), free_ptr(rgb_tab), NULL);
	return (free_tab((void **)rgb_tab_char), rgb_tab);
}

/// @brief save rgb infos
/// @param line: line
/// @param i: index
/// @return rgb ptr
int	*save_rgb(char *line, int *i)
{
	int	start;
	int	*rgb_ptr;

	rgb_ptr = NULL;
	(*i) += 1;
	start = skip_to_path(line, i);
	if (!start)
		return (0);
	cut_linebreak(line);
	trim_end_spaces(line);
	rgb_ptr = convert_rgb(&line[start], 0);
	if (!rgb_ptr)
		return (0);
	return (rgb_ptr);
}

/// @brief save txt infos
/// @param line: line
/// @param i: index
/// @return txt ptr
char	*save_txt(char *line, int *i)
{
	int		start;
	char	*txt_ptr;
	int		len;

	txt_ptr = NULL;
	(*i) += 2;
	start = skip_to_path(line, i);
	if (!start)
		return (NULL);
	cut_linebreak(line);
	len = trim_end_spaces(&line[start]);
	if (!len || !check_whitespace(&line[start]))
		return (NULL);
	txt_ptr = (char *)malloc(sizeof(char) * len + 1);
	if (!txt_ptr)
		return (NULL);
	ft_strlcpy(txt_ptr, &line[start], len + 1);
	if (!txt_ptr)
		return (NULL);
	return (txt_ptr);
}

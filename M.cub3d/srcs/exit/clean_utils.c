/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltorkia <ltorkia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:03:26 by ltorkia           #+#    #+#             */
/*   Updated: 2024/05/27 13:41:18 by ltorkia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

/// @brief free double array
/// @param tab: given double array
void	free_tab(void **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		free_ptr(tab[i++]);
	if (tab)
		free_ptr(tab);
}

/// @brief free pointer
/// @param ptr: given pointer
void	free_ptr(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

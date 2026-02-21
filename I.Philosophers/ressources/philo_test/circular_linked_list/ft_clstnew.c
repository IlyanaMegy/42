/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:16:34 by apayet            #+#    #+#             */
/*   Updated: 2022/07/28 13:06:54 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_clist	*ft_clstnew(void *content)
{
	t_clist	*new_block;

	new_block = ft_malloc(ft_get_data_addr((t_data *)0), sizeof(t_clist), 1);
	if (!new_block)
		return ((t_clist *)0);
	new_block->is_first = 1;
	new_block->is_last = 1;
	new_block->content = content;
	new_block->next = new_block;
	new_block->previous = new_block;
	return (new_block);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 11:16:05 by ilymegy           #+#    #+#             */
/*   Updated: 2023/09/24 11:16:07 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"
#include "../inc/libft.h"

void	p_move(t_list **src, t_list **dest)
{
	t_list	*node;

	if (src == NULL)
		return ;
	node = *src;
	*src = (*src)->next;
	node->next = NULL;
	ft_lstadd_front(dest, node);
	return ;
}
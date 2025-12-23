/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_integrity_one_node.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:05:58 by apayet            #+#    #+#             */
/*   Updated: 2022/05/25 10:44:22 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/**
 * @brief This function check integrety in the case of one element
 * 			this determine by bool operation if it is one element
 * 			It is also the good representation of one element when populate
 * @param stack 
 * @return int the boolean representation.
 */
int	ft_check_integrity_one_node(t_clist *stack)
{
	return ((stack->previous == stack->next)
		&& (stack->next == stack)
		&& (stack->previous == stack)
		&& (stack->is_first == 1)
		&& (stack->is_last == 1));
}

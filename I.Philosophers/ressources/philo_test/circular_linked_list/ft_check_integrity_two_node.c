/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_integrity_two_node.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:07:04 by apayet            #+#    #+#             */
/*   Updated: 2022/05/23 14:16:32 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/**
 * @brief This function check if the stack contain 2 nodes 
 * 
 * @param stack 
 * @return int 
 */
int	ft_check_integrity_two_node(t_clist *stack)
{
	t_clist	*one;
	t_clist	*two;

	one = stack;
	two = stack->next;
	return ((two->next == one)
		&& (one->previous == two)
		&& (one != two)
		&& (one->is_first == 1 && one->is_last == 0)
		&& (two->is_last == 1 && two->is_first == 0));
}

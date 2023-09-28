/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 11:16:54 by ilymegy           #+#    #+#             */
/*   Updated: 2023/09/24 11:16:56 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

/*
* get list of numbers in sorted order for real.
*/
void	do_sort(t_stack *stack, t_tools *tools)
{
	if (all_good(stack->b, stack->a))
		return;
	if (ft_pslstsize(stack->a) <= 5)
		smol_sort(stack, tools, ft_pslstsize(stack->a));
}

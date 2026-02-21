/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 17:51:34 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/06/08 22:14:21 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

int	rotate_steps(t_ps *stack, int target_nb, int steps)
{
	if (!stack)
		return (INT_MAX);
	if (stack->idx == target_nb)
		return (steps);
	if (!stack->next)
		return (INT_MAX);
	stack = stack->next;
	return (rotate_steps(stack, target_nb, (steps + 1)));
}

int	rr_steps(t_ps *stack, int target_nb, int steps)
{
	if (!stack)
		return (INT_MAX);
	if (stack->idx == target_nb)
		return (steps);
	if (!stack->prev)
		return (INT_MAX);
	stack = stack->prev;
	return (rr_steps(stack, target_nb, (steps + 1)));
}

int	reverse_rotation_is_quicker(t_ps *stack, int target_nb)
{
	int	rotation_steps;
	int	reverse_rotation_steps;

	rotation_steps = rotate_steps(stack, target_nb, 0);
	while (stack->next != NULL)
		stack = stack->next;
	reverse_rotation_steps = rr_steps(stack, target_nb, 0);
	if (reverse_rotation_steps < rotation_steps)
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 16:07:54 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/06/09 20:10:44 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

static void	resend_to_b(t_stack *s, t_tools *t, int lim)
{
	while ((s->a->idx <= lim)
		&& (s->a->idx >= t->a.nxt_idx))
		push(&s->a, &s->b, &s->instr, 'b');
}

void	return_half_to_a(t_stack *s, t_tools *t, int lim)
{
	int	len_b;

	len_b = ft_pslstsize(s->b);
	if (len_b < 50)
	{
		finish_sorting(s, t);
		return ;
	}
	start_sorting(s, t);
	resend_to_b(s, t, lim);
	return_half_to_a(s, t, lim);
}

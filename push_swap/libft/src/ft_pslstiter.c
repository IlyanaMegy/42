/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 18:39:37 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/05/29 11:08:23 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_pslstiter(t_ps *lst, void (*f)(int))
{
	t_ps	*s;

	if (lst == NULL)
		return ;
	s = lst;
	while (s != NULL)
	{
		f(s->content);
		ft_printf("\n");
		s = s->next;
	}
}

void	ft_pslstiter_reverse(t_ps *lst, void (*f)(int))
{
	t_ps	*s;

	if (lst == NULL)
		return ;
	s = lst;
	while (s->next != NULL)
		s = s->next;
	while (s != NULL)
	{
		f(s->content);
		ft_printf("\n");
		s = s->prev;
	}
}

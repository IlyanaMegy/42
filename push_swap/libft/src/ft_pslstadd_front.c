/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 00:09:46 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/05/29 11:06:54 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_pslstadd_front(t_ps **lst, t_ps *new)
{
	t_ps	*temp;

	temp = *lst;
	*lst = new;
	new->next = temp;
	temp->previous = new;
}

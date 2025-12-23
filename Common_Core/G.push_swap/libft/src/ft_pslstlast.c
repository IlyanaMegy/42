/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstlast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 00:34:06 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/05/29 11:07:29 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ps	*ft_pslstlast(t_ps *lst)
{
	t_ps	*aux;

	if (lst == NULL)
		return (lst);
	aux = lst;
	while (aux->next != NULL)
	{
		aux = aux->next;
	}
	return (aux);
}

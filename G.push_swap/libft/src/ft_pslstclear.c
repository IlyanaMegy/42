/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 12:31:38 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/05/29 12:53:08 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_pslstclear(t_ps **lst)
{
	t_ps	*s;
	t_ps	*temp;

	s = *lst;
	if (s == NULL)
		return ;
	while (s != NULL)
	{
		temp = s->next;
		free(s);
		s = temp;
	}
	*lst = NULL;
}

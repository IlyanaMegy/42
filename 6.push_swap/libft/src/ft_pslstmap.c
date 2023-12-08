/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 18:48:23 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/05/29 12:58:31 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ps	*ft_pslstmap(t_ps *lst, int (*f)(int))
{
	t_ps	*head;
	t_ps	*tmp;

	head = NULL;
	while (lst)
	{
		tmp = ft_pslstnew((*f)(lst->content));
		if (!tmp)
		{
			ft_pslstclear(&head);
			return (NULL);
		}
		ft_pslstadd_back(&head, tmp);
		lst = lst->next;
	}
	return (head);
}

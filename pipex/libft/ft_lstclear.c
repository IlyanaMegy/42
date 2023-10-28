/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeaude <pabeaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:48:40 by pabeaude          #+#    #+#             */
/*   Updated: 2022/11/30 10:34:22 by pabeaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*deux;
	t_list	*un;

	if (!del || !lst || !*lst)
		return ;
	un = *lst;
	while (un)
	{
		deux = un->next;
		ft_lstdelone(un, del);
		un = deux;
	}
	*lst = NULL;
}

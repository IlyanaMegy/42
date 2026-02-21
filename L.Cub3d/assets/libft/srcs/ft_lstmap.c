/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltorkia <ltorkia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:55:20 by ltorkia           #+#    #+#             */
/*   Updated: 2023/05/17 17:48:39 by ltorkia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void(*del)(void *))
{
	t_list	*n_list;
	t_list	*n_elm;

	if (!lst || !f || !del)
		return (0);
	n_list = 0;
	while (lst)
	{
		n_elm = ft_lstnew(f(lst->content));
		if (!n_elm)
		{
			ft_lstclear(&n_list, del);
			return (0);
		}
		ft_lstadd_back(&n_list, n_elm);
		lst = lst->next;
	}
	return (n_list);
}

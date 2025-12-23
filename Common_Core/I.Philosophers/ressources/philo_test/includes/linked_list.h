/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 13:29:50 by apayet            #+#    #+#             */
/*   Updated: 2022/04/14 15:03:28 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H

t_list		*ft_lstnew(void *content);
int			ft_lstsize(t_list *lst);
void		ft_lstadd_back(t_list **alst, t_list *new_el);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));

#endif
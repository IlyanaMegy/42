/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clist.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:56:54 by apayet            #+#    #+#             */
/*   Updated: 2022/05/25 16:37:17 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIST_H
# define CLIST_H

int		ft_check_integrity_one_node(t_clist *stack);
int		ft_check_integrity_two_node(t_clist *stack);
int		ft_clst_size(t_clist *lst);
void	ft_clstadd_back(t_clist **alst, t_clist *new_bloc);
void	ft_clstclear(t_clist **lst);

t_clist	*ft_clstnew(void *content);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 12:23:11 by apayet            #+#    #+#             */
/*   Updated: 2022/05/16 16:02:02 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/**
 * @brief This malloc function is designed ti create a linked list 
 * 	of reference malloced
 * 
 * @param game the main structure 
 * @param size the sizeof element
 * @param nbr the nbr of element
 * @return void* the return value for the nominal usage
 */
void	*ft_malloc(t_data *data, int size, int nbr)
{
	void	*container;

	container = (void *)0;
	container = malloc(size * nbr);
	if (!container)
		return ((void *)0);
	if (data[0].garbadge == (t_list *)0)
		data[0].garbadge = ft_lstnew(container);
	else
		ft_lstadd_back(&data[0].garbadge, ft_lstnew(container));
	return (container);
}

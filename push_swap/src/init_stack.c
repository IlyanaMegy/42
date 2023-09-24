/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 11:11:06 by ilymegy           #+#    #+#             */
/*   Updated: 2023/09/24 11:11:07 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"
#include "../inc/libft.h"

size_t	biggest_nb(t_list *s, int value)
{
	size_t	nbr;

	nbr = 0;
	while (s)
	{
		if (s->content->nb > value)
			nbr++;
		s = s->next;
	}
	return (nbr);
}

void	get_index(t_list *a)
{
	size_t	size;
	size_t	i;
	t_list	*first_node;

	first_node = a;
	size = ft_lstsize(a);
	while (a)
	{
		i = biggest_nb(first_node, a->content->nb);
		a->content->index = size - i - 1;
		a = a->next;
	}
}

t_list	*create_node(int value)
{
	t_stack	*node;
	t_list	*list;

	list = malloc(sizeof(*list));
	if (list == NULL)
		return (NULL);
	node = malloc(sizeof(*node));
	if (node == NULL)
	{
		free(list);
		return (NULL);
	}
	node->nb = value;
	list->content = node;
	list->next = NULL;
	return (list);
}

t_list	*init_stack(int ac, char **av)
{
	size_t	size;
	size_t	i;
	t_list	*node;
	t_list	*a;
	int		*array;

	array = check_args(ac, av, &size);
	i = 0;
	a = NULL;
	while (i < size)
	{
		node = create_node(array[i++]);
		if (node == NULL)
		{
			ft_lstclear(&a, free);
			free(array);
			end_prog("", 1);
		}
		ft_lstadd_back(&a, node);
	}
	get_index(a);
	free(array);
	return (a);
}

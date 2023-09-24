/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 11:09:06 by ilymegy           #+#    #+#             */
/*   Updated: 2023/09/24 11:09:07 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"
#include "../inc/libft.h"

void	create_stack_b(t_list **a, t_list **b, t_cmd *cmd)
{
	int	first;
	int	second;
	int	last;

	*b = NULL;
	while (ft_lstsize(*a) > 3)
	{
		first = (*a)->content->index;
		second = (*a)->next->content->index;
		last = ft_lstlast(*a)->content->index;
		if (first <= ft_lstsize(*a) / 2)
		{
			commande(8, &cmd);
			p_move(a, b);
		}
		else if (last <= ft_lstsize(*a) / 2 && last < second)
			print_n_update(5, &cmd, a, rra);
		else
			print_n_update(3, &cmd, a, ra);
	}
}

char	**get_array_single_arg(char *nbrs)
{
	char	**array;

	ft_printf("argv = %s\n", nbrs);
	array = ft_split(nbrs, 32);
	ft_printf("HERE\n");
	return (array);
}

char	**get_array_multiple_args(int ac, char **av)
{
	char			**array;
	unsigned int	i;

	array = malloc(sizeof(*array) * ((ac - 1) + 1));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (i < ((unsigned int)ac - 1))
	{
		array[i] = ft_strdup(av[i + 1]);
		if (array[i] == NULL)
		{
			free_double_char(array);
			return (NULL);
		}
		i++;
	}
	array[i] = NULL;
	return (array);
}

char	**get_array(int ac, char **av)
{
	char	**array;

	if (ac == 2)
		array = get_array_single_arg(av[1]);
	else
		array = get_array_multiple_args(ac, av);
	if (array == NULL || *array == NULL)
		end_prog("Error\n", 1);
	ft_printf("HERE\n");
	return (array);
}

int	*convert_to_int(char **array)
{
	int				*array_int;
	unsigned int	i;
	unsigned int	size;

	size = 0;
	while (array[size])
		size++;
	array_int = malloc(sizeof(*array_int) * size);
	if (array_int == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		array_int[i] = ft_atoi(array[i]);
		i++;
	}
	return (array_int);
}

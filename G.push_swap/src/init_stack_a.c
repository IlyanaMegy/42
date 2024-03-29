/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:25:35 by ilymegy           #+#    #+#             */
/*   Updated: 2023/10/03 15:25:37 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

/*
** check if there's occurences.
*/
int	is_repeated(t_ps *lst, int number)
{
	t_ps	*s;

	if (lst == NULL)
		return (0);
	s = lst;
	while (s != NULL)
	{
		if ((int)s->content == number)
			return (1);
		s = s->next;
	}
	return (0);
}

/*
** init of stack_a.
*/
void	init_stack_a(int argc, char **argv, t_ps **stack_a)
{
	int	number;
	int	i;

	i = 0;
	number = (int)ft_atoi(argv[i]);
	*stack_a = ft_pslstnew(number);
	while (i < (argc - 1))
	{
		i++;
		number = (int)ft_atoi(argv[i]);
		if (is_repeated(*stack_a, number))
		{
			ft_pslstclear(stack_a);
			end_prog("Error\n", 1);
		}
		else
			ft_pslstadd_back(stack_a, ft_pslstnew(number));
	}
}

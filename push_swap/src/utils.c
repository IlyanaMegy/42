/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 11:25:37 by ilymegy           #+#    #+#             */
/*   Updated: 2023/09/24 11:25:40 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

void	end_prog(char *msg, int exit_nb)
{
	ft_printf("%s\n", msg);
	exit(exit_nb);
}

int	all_good(t_ps *s_a, t_ps *s_b)
{
	int		max_value;
	t_ps	*lst;

	if (s_b != NULL)
		return (0);
	if (ft_pslstsize(s_a) == 1)
		return (1);
	lst = s_a;
	max_value = s_a->content;
	lst = lst->next;
	while (lst)
	{
		if (max_value < lst->content)
			max_value = lst->content;
		else
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	is_sorted(t_ps *stack)
{
	if (stack)
	{
		while (stack->next != NULL)
		{
			if (stack->content > stack->next->content)
				return (0);
			stack = stack->next;
		}
	}
	return (1);
}

int	is_full(t_ps *stack, int total_numbers)
{
	int	numbers_in_stack;

	numbers_in_stack = 0;
	while (stack->next != NULL)
	{
		numbers_in_stack++;
		stack = stack->next;
	}
	numbers_in_stack++;
	if (numbers_in_stack == total_numbers)
		return (1);
	return (0);
}

void	p_lsts(t_ps *s_A, t_ps *s_B)
{
	t_ps *a;
	t_ps *b;

	ft_printf("\n_________________\n\n");
	a = s_A;
	b = s_B;
	ft_printf("a : ");
	if (a)
	{
		while (a->next)
		{
			ft_printf("%d ", a->content);
			a = a->next;
		}
		ft_printf("%d\n", a->content);
	}
	else
		ft_printf("\n");
	ft_printf("b : ");
	if (b)
	{
		while (b->next)
		{
			ft_printf("%d ", b->content);
			b = b->next;
		}
		ft_printf("%d\n", b->content);
	}
	else
		ft_printf("\n");
	ft_printf("_________________\n\n");
}

void	print_tab(int *tab, int len)
{
	int i = 0;
	while (i < len)
	{
		ft_printf("%d ", tab[i]);
		i++;
	}
	ft_printf("\n");	
}
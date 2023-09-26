/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:18:29 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/06/14 16:15:09 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	return_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	clear(t_stack *stack, t_aux *aux)
{
	ft_dlstclear(&stack->a);
	ft_dlstclear(&stack->b);
	ft_lstclear(&stack->instr, &free);
	free(aux->ordered_array);
}

void	p_lsts(t_dlist *s_A, t_dlist *s_B)
{
	t_dlist *a;
	t_dlist *b;

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
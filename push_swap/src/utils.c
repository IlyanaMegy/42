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

void	free_double_char(char **arr_char)
{
	size_t	i;

	i = 0;
	while (arr_char[i])
	{
		free(arr_char[i]);
		i++;
	}
	free(arr_char);
}

void	end_prog(char *msg, int exit_nb)
{
	ft_printf("%s\n", msg);
	exit(exit_nb);
}

void	end_n_free(char **array, char *msg, int exit_nb)
{
	free_double_char(array);
	end_prog(msg, exit_nb);
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
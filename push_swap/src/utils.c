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
#include "../inc/libft.h"

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

void	print_double_array(char **a)
{
	int	i;

	i = 0;
	while (a[i])
	{
		ft_printf("\"%s\" ", a[i]);
		i++;
	}
	ft_printf("\n");
}

void	end_n_free(char **array, char *msg, int exit_nb)
{
	free_double_char(array);
	end_prog(msg, exit_nb);
}

void	print_lst(t_list *mylist, char pile)
{
	t_list	*lst;

	ft_printf("\n");
	if (mylist)
	{
		lst = mylist;
		while (lst->next)
		{
			ft_printf("%d\n", lst->content->nb);
			lst = lst->next;
		}
		ft_printf("%d\n--------\n%c\n", lst->content->nb, pile);
		return ;
	}
	ft_printf("--------\n%c\n", pile);
}

void	p_lsts(t_list *s_A, t_list *s_B)
{
	t_list *a;
	t_list *b;

	ft_printf("\n_________________\n\n");
	a = s_A;
	b = s_B;
	ft_printf("a : ");
	if (a)
	{
		while (a->next)
		{
			ft_printf("%d ", a->content->nb);
			a = a->next;
		}
		ft_printf("%d\n", a->content->nb);
	}
	else
		ft_printf("\n");
	ft_printf("b : ");
	if (b)
	{
		while (b->next)
		{
			ft_printf("%d ", b->content->nb);
			b = b->next;
		}
		ft_printf("%d\n", b->content->nb);
	}
	else
		ft_printf("\n");
	ft_printf("_________________\n\n");
}

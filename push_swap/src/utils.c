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

void	print_tab(int *tab)
{
	size_t	i;

	ft_printf("\n-----\ntab :\n-----\n");
	i = 0;
	while (tab[i])
	{
		ft_printf("%d : %d\n", i, tab[i]);
		i++;
	}
	ft_printf("\n");
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

void	print_lists(t_list *s_A, t_list *s_B)
{
	t_list *a;
	t_list *b;

	ft_printf("\n");
	a = s_A;
	b = s_B;
	while ((a && a->next) ||(b && b->next))
	{
		if (a && a->next)
		{
			ft_printf("%d", a->content->nb);
			a = a->next;
		}
		else
			ft_printf(" ");
		if (b && b->next)
		{
			ft_printf("\t\t%d\n", b->content->nb);
			b = b->next;
		}
		else
			ft_printf("\t\t \n");
	}
	if (a)
		ft_printf("%d", a->content->nb);
	else
		ft_printf(" ");
	if (b)
		ft_printf("\t\t%d\n", b->content->nb);
	else
		ft_printf("\t\t \n");
	ft_printf("-----\t\t-----\na\t\tb\n");
	ft_printf("---------------------------\n\n");
	return ;
}
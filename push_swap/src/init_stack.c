#include "../inc/pushswap.h"

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
	t_list	*stack_a;
	int		*array;

	array = check_args(ac, av, &size);
	i = 0;
	stack_a = NULL;
	while (i < size)
	{
		node = create_node(array[i++]);
		if (node == NULL)
		{
			ft_lstclear(&stack_a, free);
			free(array);
			end_prog("", 1);
		}
		if (!stack_a)
			ft_lstnew(node);
		else
			ft_lstadd_back(&stack_a, node);
	}
	free(array);
	// ft_printf("content is : %s\n", (char *)stack_a->content);
	return (stack_a);
}

// char	*get_number(char *s)
// {
// 	char	*tmp;
// 	int		j;

// 	j = 0;
// 	while (s[j])
// 		j++;
// 	tmp = malloc(sizeof(char) * (j + 1));
// 	if (!tmp)
// 		return (NULL);
// 	j = 0;
// 	while (s[j])
// 	{
// 		tmp[j] = s[j];
// 		j++;
// 	}
// 	tmp[j] = '\0';
// 	if (!ft_strlen(tmp))
// 		return (NULL);
// 	else if (!ft_atoi(tmp))
// 		if (!(ft_strlen(tmp) == 1 && tmp[0] == '0'))
// 			return (NULL);
// 	return (tmp);
// }

// int	fill_pA(char **av)
// {
// 	int i;
// 	char *tmp;
// 	t_pA *pA;

// 	i = 1;
// 	// pA = lstnew(0);
// 	while (av[i])
// 	{
// 		tmp = get_number(av[i]);
// 		if (!tmp)
// 			return (1);
// 		ft_printf("tmp = %s\n", tmp);
// 		lstadd_back(&pA, lstnew(atoi(tmp)));
// 		free(tmp);
// 		i++;
// 	}
// 	print_list(pA);
// 	return (0);
// }
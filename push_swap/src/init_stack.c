#include "../inc/pushswap.h"

int	init_stack(int ac, char **av)
{
	size_t	size;
	int		i;

	// t_list			*node;
	// t_list			*stack_a;
	// int				*array;
	i = check_args(ac, av, &size);
	ft_printf("i = %d\n", i);
	// i = 0;
	// stack_a = NULL;
	return (0);
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
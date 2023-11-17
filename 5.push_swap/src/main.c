/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 11:12:02 by ilymegy           #+#    #+#             */
/*   Updated: 2023/09/24 11:12:03 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

/*
** check if arg is an int.
*/
void	check_is_int(char **argv, int i)
{
	int			j;
	long int	number;

	j = 0;
	if (argv[i][j] == '-')
	{
		j++;
		if (!argv[i][j])
			end_prog("Error\n", 1);
	}
	while (argv[i][j])
	{
		if (!(ft_isdigit(argv[i][j])))
			end_prog("Error\n", 1);
		j++;
	}
	number = ft_atoi(argv[i]);
	if (number > INT_MAX || number < INT_MIN)
		end_prog("Error\n", 1);
}

/*
** if argv is a single string, it checks if valid 
** then split to char**, each number is inside a char*.
*/
char	**check_string(int *argc, char **argv)
{
	int	i;

	i = 0;
	if (!(argv[0][0]))
		end_prog("", 1);
	argv = ft_split(argv[0], ' ');
	if (argv == NULL)
		end_prog("", 1);
	while (argv[i] != NULL)
		i++;
	*argc = i;
	return (argv);
}

/*
** for each arg, check if it's an int.
*/
void	check_args(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		check_is_int(argv, i);
		i++;
	}
}

/*
** init the stacks and instructions to NULL.
*/
void	init_stacks(t_stack *stack)
{
	stack->a = NULL;
	stack->b = NULL;
	stack->instr = NULL;
}

/*
** just a main here...
** gonna check args, then init stacks, filling stack_a and then sort it.
*/
int	main(int ac, char **av)
{
	t_stack	stack;
	t_tools	tools;
	int		i;

	i = 0;
	if (ac == 1)
		exit(1);
	av = &av[1];
	ac--;
	if (ac == 1)
	{
		i = ac;
		av = check_string(&ac, av);
	}
	check_args(ac, av);
	init_stacks(&stack);
	init(&stack, &tools, ac, av);
	do_sort(&stack, &tools);
	reduce_instructions(&stack.instr);
	ft_lstiter(stack.instr, &ft_putstr);
	clear(&stack, &tools);
	if (i == 1)
		free_av(av);
}

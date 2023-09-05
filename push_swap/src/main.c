#include "../inc/pushswap.h"

void	end_prog(char *msg, int exit_nb)
{
	ft_printf("%s\n", msg);
	exit(exit_nb);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	// t_list	*stack_b;

	if (ac == 1)
	{
		end_prog("Error", 1);
		return (1);
	}
	stack_a = init_stack(ac, av);
	if (stack_a)
		ft_printf("good\n");
	// stack_b = NULL;
	// print_list(stack_a->content);
	return (0);
}
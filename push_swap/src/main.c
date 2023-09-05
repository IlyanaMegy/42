#include "../inc/pushswap.h"
#include "../inc/libft.h"

void	end_prog(char *msg, int exit_nb)
{
	ft_printf("%s\n", msg);
	exit(exit_nb);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (ac == 2)
	{
		end_prog("Error", 1);
		return (1);
	}
	stack_a = init_stack(ac, av);
	stack_b = NULL;
	if (push_swap(stack_a, stack_b))
	{
		ft_lstclear(&stack_a, free);
		ft_printf("already in order\n");
		return (0);
	}
	return (0);
}
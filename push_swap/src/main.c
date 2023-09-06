#include "../inc/pushswap.h"
#include "../inc/libft.h"

void	end_prog(char *msg, int exit_nb)
{
	ft_printf("%s\n", msg);
	exit(exit_nb);
}

void	finish_prog(t_list *a, t_list *b, char *msg)
{
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
	free(a);
	free(b);
	ft_printf("%s", msg);
	exit(0);
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
	if (all_good(stack_a, stack_b))
	{
		ft_lstclear(&stack_a, free);
		return (0);
	}
	push_swap(&stack_a, &stack_b);
	finish_prog(stack_a, stack_b, "");
	return (0);
}
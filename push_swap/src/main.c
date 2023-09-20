#include "../inc/pushswap.h"
#include "../inc/libft.h"

void	end_prog(char *msg, int exit_nb)
{
	ft_printf("%s\n", msg);
	exit(exit_nb);
}

void	finish_prog(t_list *a, t_list *b, t_cmd *cmd, char *msg)
{
	if (cmd->cmd)
		execute_sep(0, cmd);
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
	free(a);
	free(b);
	free(cmd);
	ft_printf("%s", msg);
	exit(0);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_cmd	*cmd;

	if (ac == 2)
	{
		end_prog("Error", 1);
		return (1);
	}
	stack_a = init_stack(ac, av);
	stack_b = NULL;
	cmd = malloc(sizeof(*cmd));
	if (cmd == NULL)
		finish_prog(stack_a, stack_b, cmd, "");
	cmd->cmd = -1;
	cmd->next = NULL;
	if (all_good(stack_a, stack_b))
	{
		ft_lstclear(&stack_a, free);
		free(stack_a);
		free(cmd);
		return (0);
	}
	push_swap(&stack_a, &stack_b, cmd);
	finish_prog(stack_a, stack_b, cmd, "");
	return (0);
}
#include "../inc/pushswap.h"
#include "../inc/libft.h"

// sa 1
// sb 2
// ra 3
// rb 4
// rra 5
// rrb 6
// pa 7
// pb 8

void	print_n_update(int c, t_cmd **cmd, t_list **l, void move())
{
	commande(c, cmd);
	move(l);
}

void	commande(int command, t_cmd **cmd)
{
	int	first;

	first = (*cmd)->cmd;
	if ((*cmd)->cmd == -1)
    {
        (*cmd)->cmd = command;
        return ;
    }
    // ft_printf("first = %d, cmd = %d\n", first, command);
    if ((first == 1 && command == 2) || (first == 2 && command == 1))
        ft_printf("ss\n");
    else if ((first == 3 && command == 4) || (first == 4 && command == 3))
        ft_printf("rr\n");
    else if ((first == 5 && command == 6) || (first == 6 && command == 5))
        ft_printf("rrr\n");
    else
        execute_sep(command, *cmd);
    (*cmd)->cmd = -1;
}

void	execute_sep(int command, t_cmd *cmd)
{
    if (command == 1 || cmd->cmd == 1)
        ft_printf("sa\n");
    if (command == 2 || cmd->cmd == 2)
        ft_printf("sb\n");
    if (command == 3 || cmd->cmd == 3)
        ft_printf("ra\n");
    if (command == 4 || cmd->cmd == 4)
        ft_printf("rb\n");
    if (command == 5 || cmd->cmd == 5)
        ft_printf("rra\n");
    if (command == 6 || cmd->cmd == 6)
        ft_printf("rrb\n");
    if (command == 7 || cmd->cmd == 7)
        ft_printf("pa\n");
    if (command == 8 || cmd->cmd == 8)
        ft_printf("pb\n");
}
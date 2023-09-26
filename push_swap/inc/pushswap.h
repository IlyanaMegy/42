#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include "libft.h"
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

// # define T_LIST

// typedef struct s_stack
// {
// 	int				nb;
// 	size_t			index;
// 	size_t			final;
// 	int				pos;
// }					t_stack;

// typedef struct s_list
// {
// 	t_stack			*content;
// 	struct s_list	*next;
// }					t_list;

// typedef struct s_cmd
// {
// 	int				cmd;
// 	struct s_cmd	*next;
// }					t_cmd;

typedef struct s_stack
{
	t_ps		*a;
	t_ps		*b;
	t_list		*instr;
}				t_stack;

typedef struct s_a_utils
{
	int			mid_idx;
	int			high_idx;
	int			nxt_idx;
}				t_a_utils;

typedef struct s_b_utils
{
	int			mid_idx;
	int			high_idx;
	int			low_idx;
}				t_b_utils;

typedef struct s_tools
{
	int			*ordered_array;
	int			total_num;
	t_a_utils	a;
	t_b_utils	b;
}				t_tools;

// init.c
void			init(t_stack *stack, t_tools *tools, int ac, char **av);
// init _stack_a.c
void			init_stack_a(int argc, char **argv, t_ps **stack_a);

// sort_tools.c
int				mid_idx(int bigger_idx, int smoler_idx);
void			rewind(t_ps **stack_to_rewind);

// utils.c
void			p_lsts(t_ps *s_A, t_ps *s_B);
void			end_prog(char *msg, int exit_nb);
void			print_tab(int *tab, int len);

// quick_sort.c
void			quick_sort(int *arr, int n);

#endif
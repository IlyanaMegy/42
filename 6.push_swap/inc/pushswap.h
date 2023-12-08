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
void			order_a(t_stack *stack, t_tools *t);

// utils.c
void			p_lsts(t_ps *s_A, t_ps *s_B);
void			end_prog(char *msg, int exit_nb);
void			clear(t_stack *stack, t_tools *t);
void			free_av(char **av);
int				is_sorted(t_ps *stack);
int				is_full(t_ps *stack, int total_numbers);

// quick_sort.c
void			quick_sort(int *arr, int n);

// push_swap.c
void			do_sort(t_stack *stack, t_tools *tools);

// smol_sort.c
void			smol_sort(t_stack *s, t_tools *tools, int total_nb);

// moves.c
void			swap(t_ps **s, t_list **cmd, char pile);
void			rotate(t_ps **s, t_list **cmd, char pile);
void			reverse_rotate(t_ps **s, t_list **cmd, char pile);
void			push(t_ps **src_s, t_ps **dest_s, t_list **cmd, char pile);
void			init_empty_s(t_ps *dest, t_list **cmd, t_ps **dest_s, char id);

// return_to_a_sorting.c
void			start_sorting(t_stack *s, t_tools *t);
void			finish_sorting(t_stack *s, t_tools *t);

// return_to_a.c
void			return_half_to_a(t_stack *stack, t_tools *t, int lim);

// half_to_b.c
void			half_to_b(t_stack *stack, t_tools *tools);

// smart_rotate.c
int				reverse_rotation_is_quicker(t_ps *stack, int target_nb);

// reduce_instr.c
void			reduce_instructions(t_list **instructions);

#endif
#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define T_LIST

typedef struct s_stack
{
	int				nb;
	size_t			index;
}					t_stack;
typedef struct s_list
{
	t_stack			*content;
	struct s_list	*next;
}					t_list;

// main.c
void				end_prog(char *msg, int exit_nb);
void				finish_prog(t_list *a, t_list *b, char *msg);

// init_stack.c
t_list				*init_stack(int ac, char **av);

// check_args.c
int					*check_args(int ac, char **av, size_t *s);

// get_array.c
char				**get_array(int ac, char **av);
int					*convert_to_int(char **array);
void				create_stack_b(t_list **a, t_list **b);

// utils.c
void				free_double_char(char **arr_char);
void				print_double_array(char **a);
void				end_n_free(char **array, char *msg, int exit_nb);
void				print_tab(int *tab);
void				print_lst(t_list *mylist, char pile);
void				print_lists(t_list *s_A, t_list *s_B);
void				p_lsts(t_list *s_A, t_list *s_B);

// pushswap.c
int					push_swap(t_list **s_a, t_list **s_b);
int					all_good(t_list *s_a, t_list *s_b);
int					in_order(t_list *lst);

// pa_pb.c
void				p_move(t_list **src, t_list **dest, char p);

// sa_sb.c
void				sa(t_list **a);
void				sb(t_list **b);
void				ss(t_list **a, t_list **b);

// rra_rrb.c
void				rra(t_list **a);
void				rrb(t_list **b);
void				rrr(t_list **a, t_list **b);

// ra_rb.c
void				ra(t_list **a);
void				rb(t_list **b);
void				rr(t_list **a, t_list **b);

// three_or_less.c
int				three_or_less(t_list **a);

// five_or_less.c
void				five_or_less(t_list **a, t_list **b);
#endif
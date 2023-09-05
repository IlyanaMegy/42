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
}					t_stack;
typedef struct s_list
{
	t_stack			*content;
	struct s_list	*next;
}					t_list;

// main.c
void				end_prog(char *msg, int exit_nb);

// init_stack.c
t_list				*init_stack(int ac, char **av);

// check_args.c
int					*check_args(int ac, char **av, size_t *s);

// get_array.c
char				**get_array(int ac, char **av);
int					*convert_to_int(char **array);

// utils.c
void				free_double_char(char **arr_char);
void				print_double_array(char **a);
void				end_n_free(char **array, char *msg, int exit_nb);
void				print_tab(int *tab);
void				print_lst(t_list *mylist);

// pushswap.c
int					push_swap(t_list *s_a, t_list *s_b);

#endif
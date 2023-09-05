#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include "../inc/libft.h"

# ifndef T_LIST
#  define T_LIST

typedef struct s_list
{
	t_stack			*content;
	struct s_list	*next;
}					t_list;
# endif

typedef struct s_stack
{
	int				nb;
}					t_stack;
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

#endif
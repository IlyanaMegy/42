#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "../inc/libft.h"

typedef struct s_pA
{
	int			nb;
	struct s_pA	*next;
}				t_pA;

typedef struct s_pB
{
	int			nb;
	struct s_pB	*next;
}				t_pB;

// main
void			end_prog(char *msg, int exit_nb);

// // verifs
int				check_args(char **av);
int				fill_pA(char **av, t_pA **pA);
// char			*get_number(size_t *start, size_t *end, char *s);

// // convert_intab
// int				*int_tab(char *pX, t_ps *ps, int *nb_nb);
// void			print_tab(int *tab);

// // push_swap
// void			push_swap(t_ps *ps);
#endif
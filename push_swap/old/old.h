#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "../inc/libft.h"

typedef struct s_tab
{
	int		*tab;
	int		nb_nbr;
}			t_tab;

typedef struct s_ps
{
	char	*pileA;
	char	*pileB;
	int		len_pA;
	int		len_pB;
	t_tab	intab_pA;
	t_tab	intab_pB;
	int		nb_nbrA;
	int		nb_nbrB;
}			t_ps;

// main
void		end_prog(void);

// verifs
int			check_args(char **av);
int			fill_pA(char **av, char **pA);
char		*get_number(size_t *start, size_t *end, char *s);

// convert_intab
int			*int_tab(char *pX, t_ps *ps, int *nb_nb);
void		print_tab(int *tab);

// push_swap
void		push_swap(t_ps *ps);
#endif
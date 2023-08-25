#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "../inc/libft.h"

typedef struct s_ps
{
	char	*pileA;
	char	*pileB;
	int		len_pA;
	int		len_pB;
	int		*intab_pA;
	int		*intab_pB;
}			t_ps;

// main
void		end_prog(void);

// verifs
int			check_args(char **av);
int			fill_pA(char **av, char **pA);
char		*get_number(size_t *start, size_t *end, char *s);

// convert_intab
int			*int_tab(char *pX, t_ps *ps);
void		print_tab(int *tab);

// push_swap
void		push_swap(t_ps *ps);
#endif
#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "../inc/libft.h"

typedef struct s_ps
{
	char	*pileA;
	char	*pileB;
	int		len_pA;
	int		len_pB;
}			t_ps;

// main
void		end_prog(void);

// verifs
int			check_args(char **av);
int			fill_pA(char **av, char **pA);

// push_swap
int			in_order(char *pX, int len);
#endif
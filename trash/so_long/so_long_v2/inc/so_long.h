#ifndef SO_LONG_H
# define SO_LONG_H

# include <errno.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_game
{
	void	*mlx_ptr;
	void	*mlx_win;
}			t_game;

#endif
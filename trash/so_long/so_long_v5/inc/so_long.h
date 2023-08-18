#ifndef SO_LONG_H
# define SO_LONG_H

// COLORS
# define RED "\033[1m\033[31m"
# define GREEN "\033[1m\033[32m"

// EVENTS
# define ON_DESTROY 17
# define KEY_PRESSED 2
# define KEY_RELEASED 3
# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100
# define ESC 65307

# define NO_EVENT_MASK 0
# define KEY_RELEASED_MASK 2

// INCLUDES
# include "../inc/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdlib.h> //malloc
# include <string.h>
# include <unistd.h> //read, close, write

// STRUCTURES
typedef struct s_game
{
	void	*mlx_ptr;
	void	*mlx_win;
}			t_game;

// TOOLS
enum		e_state
{
	event_end = -1,
	game_over = -1,
	error = 2,
	file_error = 3,
	map_char_error = 4,
};

// FUNCTIONS
void		destroy_the(t_game *game);
void		end_game(char *msg, t_game *game, enum e_state state);

#endif
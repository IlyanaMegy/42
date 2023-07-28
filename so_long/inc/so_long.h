#ifndef SO_LONG_H
# define SO_LONG_H

// COLORS
# define RED "\033[1m\033[31m"
# define GREEN "\033[1m\033[32m"

// EVENTS
# define ON_DESTROY 17
# define KEY_PRESSED 2
# define KEY_RELEASED 3
# define NO_EVENT_MASK 0
# define KEY_RELEASED_MASK 2

// INCLUDES
# include "../inc/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <errno.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdlib.h> //malloc
# include <string.h>
# include <unistd.h> //read, close, write

// STRUCTURES

typedef struct s_vector
{
	int			x;
	int			y;
}				t_vector;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*mlx_win;
	int			x_p;
	int			y_p;
	void		*wall_img;
	void		*collec_img;
	void		*main_img;
	void		*enemy_img;
	void		*exit_img;
	void		*bg_img;
	t_vector	img_size;
	char		**map;
	t_vector	map_size;
	t_vector	p_pos;
	int			nb_collectible;
	int			moves;
}				t_game;

typedef struct s_game_map
{
	int			c;
	int			p;
	int			e;
	int			x;
	int			y;
}				t_game_map;

// TOOLS
enum			e_state
{
	event_end = -1,
	game_over = -1,
	map_error = 2,
	file_error = 3,
	init_error = 4,
};

// FUNCTIONS
// exit game
void			free_map(char **map);
void			destroy_the(t_game *game);
void			end_game(char *msg, t_game *game, enum e_state state,
					char *free_me);
int				exit_event(t_game *game);

// init game
void			init_game(t_game *game, char *map_file);

// init map && init map utils
char			**get_map(char *map_file, t_game *game);
void			render_map(t_game *game);

// check map
void			check_map_rect(t_game *game);
void			check_map_walls(t_game *game);
void			check_map_elem(t_game *game, t_game_map *map);
void			is_map_playable(t_game *game, char *map_file);
void			show_table(char **map);

// check map utils
int				get_height(char **map);
int				check_line(char *line);
void			check_map_valid(t_game *game, char *map_file);
int				to_find(char *str, char c);

// move to
void			move_to(int x, int y, char *img_path, t_game *game);
int				is_wall(t_game *game, int y, int x);
#endif
#ifndef SO_LONG_H
#define SO_LONG_H

// COLORS
#define RED "\033[1m\033[31m"
#define GREEN "\033[1m\033[32m"

// EVENTS
#define ON_DESTROY 17
#define KEY_PRESSED 2
#define KEY_RELEASED 3
#define NO_EVENT_MASK 0
#define KEY_RELEASED_MASK 2

// INCLUDES
#include "../inc/libft.h"
#include <errno.h>
#include <fcntl.h>
#include <mlx.h>
#include <stdlib.h> //malloc
#include <string.h>
#include <unistd.h> //read, close, write
#include <X11/X.h>
#include <X11/keysym.h>

// STRUCTURES

typedef struct s_vector
{
	int x;
	int y;
} t_vector;

typedef struct s_game
{
	void *mlx_ptr;
	void *mlx_win;
	int win_w;
	int win_h;
	int x_p;
	int y_p;
	void *wall_img;
	void *collec_img;
	void *rick_img;
	void *wong_img;
	void *exit_img;
	void *bg_img;
	t_vector img_size;
	char **map;
} t_game;


typedef struct s_game_map
{
	int c;
	int p;
	int e;
	int x;
	int y;
} t_game_map;

// TOOLS
enum e_state
{
	event_end = -1,
	game_over = -1,
	error = 2,
	file_error = 3,
	map_char_error = 4,
};

// FUNCTIONS
// exit game
void destroy_the(t_game *game);
void end_game(char *msg, t_game *game, enum e_state state);
int exit_event(t_game *game);

// init game
void init_game(t_game *game, char *map_file);

// init map
void get_map(char *map_file, t_game *game);
int get_height(char **map);
void render_map(t_game *game);

// check map
void check_map_rect(t_game *game);
void check_map_walls(t_game *game);
void check_map_elem(t_game *game);
void show_table(t_game *game);

//check map utils
void unknown_element(t_game **game);
int check_line(char *line);
#endif
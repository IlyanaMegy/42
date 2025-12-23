/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltorkia <ltorkia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:56:41 by ltorkia           #+#    #+#             */
/*   Updated: 2024/07/04 16:30:08 by ltorkia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../assets/libft/inc/libft.h"
# include "../assets/minilibx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

//  -------------------------------------------------------------------------
// |								MESSAGES								|
// -------------------------------------------------------------------------

// ARGUMENTS
# define ERR_USAGE "./cub3d <maps/map.cub>"
# define ERR_ARGS "Invalid arguments"
# define ERR_UNKNOWN_FILE "File not found"
# define ERR_EMPTY_FILE "This file is empty"
# define ERR_FILE_IS_DIR "Is a directory"

// TEXTURES + RGB COLORS
# define ERR_TEX_N_INVALID "Invalid north texture"
# define ERR_TEX_S_INVALID "Invalid south texture"
# define ERR_TEX_W_INVALID "Invalid west texture"
# define ERR_TEX_E_INVALID "Invalid east texture"
# define ERR_COLOR_FLOOR "Invalid floor RGB color"
# define ERR_COLOR_CEILING "Invalid ceiling RGB color"
# define ERR_TEX_COLOR_DOUBLE "Double texture / rgb color detected"
# define ERR_TEX_COLOR_MISSING "Missing color(s) or texture(s)"
# define ERR_INVALID_LINE "Invalid line"

// MAP
# define ERR_EMPTY_MAP "This map is empty"
# define ERR_INVALID_MAP "Wrong map: either empty or misaligned"
# define ERR_MAP_TOO_SMALL "This map is not at least 3 lines high"
# define ERR_INCOMPLETE_MAP "Incomplete map"
# define ERR_INV_LETTER "Invalid character in map"
# define ERR_NEWLINE "'\\n' in map forbidden"
# define ERR_MAP_NO_WALLS "Invalid wall placement"
# define ERR_MAP_SPACES "This map has spaces inside"

// PLAYER
# define ERR_NUM_PLAYER "Map has more than one player"
# define ERR_PLAYER_DIR "Missing player (expected N, S, E or W)"

// MALLOC / INIT
# define ERR_MALLOC "Could not allocate memory"
# define ERR_MLX_INIT "Could not init mlx"
# define ERR_OPEN_MAP "Could not open map"
# define ERR_MLX_WIN "Could not create mlx window"
# define ERR_MLX_IMG "Could not create mlx image"

//  -------------------------------------------------------------------------
// |								WINDOW									|
// -------------------------------------------------------------------------

# define WIN_WIDTH 1200
# define WIN_HEIGHT 900
# define DIST_EDGE_MOUSE_WRAP 20
# define MOVESPEED 0.04
# define ROTSPEED 0.02

# define TEX_SIZE 64
# define MINIMAP 1

//  -------------------------------------------------------------------------
// |								COLORS									|
// -------------------------------------------------------------------------

# define RESET "\033[0m"
# define BOLD "\033[1m"
# define ITALIC "\033[3m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"

//  -------------------------------------------------------------------------
// |									MAP									|
// -------------------------------------------------------------------------

typedef struct s_map
{
	char			**file;
	char			**map;
	char			*path;
	int				fd;
	int				line_count;
	int				height;
	int				width;
}					t_map;

//  -------------------------------------------------------------------------
// |								RAYCASTING								|
// -------------------------------------------------------------------------

/**
 * @brief  ray's data
 * @note   dir_x / dir_y = player->dir + player->plane * camera_x
 * @note   map_x / map_y = (int)player->pos
 * @note   step_x / y : increment map_x / y depends on sidedist_x < sidedist_y
 * @note   sidedist_x / y = distance from the ray start position to next x / y
 * @note   deltadist_x / deltadist_y = fabs(1 / ray->dir)
 * @note   wall_dist : wall distance sidedist - deltadist depends on side
 * @note   wall_x : player->pos + wall_dist * dir depends on side
 * @note   side : sidedist_x < sidedist_y -> 0, else -> 1
 * @note   line_height : (int)(data->win_height / wall_dist)
 * @note   draw_start / draw_end : start and end of texture to draw
*/
typedef struct s_ray
{
	double			camera_x;
	double			dir_x;
	double			dir_y;
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	double			sidedist_x;
	double			sidedist_y;
	double			deltadist_x;
	double			deltadist_y;
	double			wall_dist;
	double			wall_x;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
}					t_ray;

//  -------------------------------------------------------------------------
// |							TEXTURES / IMAGES							|
// -------------------------------------------------------------------------

enum				e_texture_index
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3
};

typedef struct s_txt
{
	char			*north_path;
	char			*south_path;
	char			*west_path;
	char			*east_path;
	int				*floor_rgb;
	int				*ceil_rgb;
	unsigned long	hex_floor;
	unsigned long	hex_ceiling;
	int				size;
	int				index;
	double			step;
	double			pos;
	int				x;
	int				y;
}					t_txt;

typedef struct s_img
{
	void			*img;
	int				*addr;
	int				pixel_bits;
	int				size_line;
	int				endian;
}					t_img;

//  -------------------------------------------------------------------------
// |									MINIMAP								|
// -------------------------------------------------------------------------

# ifndef MMAP_DEBUG_MSG
#  define MMAP_DEBUG_MSG 0
# endif
# define MMAP_PIXEL_SIZE 128
# define MMAP_VIEW_DIST 4
# define MMAP_COLOR_PLAYER 0xD6CECF
# define MMAP_COLOR_WALL 0x2F2D2E
# define MMAP_COLOR_FLOOR 0x808080
# define MMAP_COLOR_SPACE 0x404040

/**
 * @brief  minimap's data
 * @note   map : 2D map
 * @note   img : t_img struct
 * @note   size : (2 * view_dist) + 1
 * @note   offset_x / y : position x / y in minimap of player
 * @note   view_dist : MMAP_VIEW_DIST
 * @note   tile_size : MMAP_PIXEL_SIZE / (2 * view_dist)
*/
typedef struct s_minimap
{
	char			**map;
	t_img			*img;
	int				size;
	int				offset_x;
	int				offset_y;
	int				view_dist;
	int				tile_size;
}					t_minimap;

//  -------------------------------------------------------------------------
// |									PLAYER								|
// -------------------------------------------------------------------------

/**
 * @brief   player's data
 * @note    dir : N,S,E,W
 * @note	pos_x / pos_y : position changing with keys WASD
 * @note	dir_x / dir_y : direction changing with arrow keys
 * @note	has_moved : += 1 when key WASD or arrows pressed
 * @note	plane_x / plane_y : ?
 * @note	move_x : -1 = left,  1 = right / move_y : -1 = down, 1 = up
 * @note	rotate : -1 = arrow left, 1 = arrow right
*/
typedef struct s_player
{
	char			dir;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	int				has_moved;
	int				move_x;
	int				move_y;
	int				rotate;
}					t_player;

//  -------------------------------------------------------------------------
// |							DATA / GAME									|
// -------------------------------------------------------------------------

typedef struct s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				win_height;
	int				win_width;
	t_player		player;
	t_map			map;
	t_txt			txt;
	t_ray			ray;
	t_img			minimap;
	int				**texture_pixels;
	int				use_mouse;
	int				**textures;
}					t_data;

//  -------------------------------------------------------------------------
// |								PARSING									|
// -------------------------------------------------------------------------

// srcs/parsing/check_file.c
bool				file_is_valid(char *file, char *ext);
bool				extension_is_valid(char *path, char *ext);
bool				path_exists(char *path);
bool				path_is_dir(char *path);

// srcs/parsing/parser.c
bool				parse_all(t_data *data, char *path);

// srcs/parsing/parser_utils.c
bool				line_is_empty(char *line);
bool				check_empty_lines(t_data *data, int (*row), bool map_check);
bool				check_double_txt(t_data *data, char **file, int (*row));
void				spaces_into_walls(char **map);

// srcs/parsing/parse_infos.c
bool				parse_infos(t_data *data, char **file, int row);

// srcs/parsing/parse_infos_utils.c
char				*save_txt(char *line, int *i);
int					*save_rgb(char *line, int *i);

// srcs/parsing/create_map.c
bool				create_map(t_data *data, char **file, int (*row));

// srcs/parsing/create_map_utils.c
size_t				get_max_len(char **file, int row);
int					check_chars(t_data *data, char **file, int row);

// srcs/parsing/check_map.c
bool				map_is_valid(t_data *data, char **map);

// srcs/parsing/check_map_utils.c
int					to_top(char **map, int i, int j);
int					to_bottom(char **map, int i, int j);
int					to_left(char **map, int i, int j);
int					to_right(char **map, int i, int j);

// srcs/parsing/utils.c
void				cut_linebreak(char *s);
bool				check_whitespace(char *s);
int					trim_end_spaces(char *s);
bool				check_commas(char *s);

//  -------------------------------------------------------------------------
// |								INIT									|
// -------------------------------------------------------------------------

// srcs/init/init_textures.c
void				init_textures(t_data *data);
void				init_img(t_data *data, t_img *image, int width, int height);

// srcs/init/init_data.c
void				init_img_clean(t_img *img);
void				init_ray(t_ray *ray);

// srcs/init/textures.c
void				init_texture_pixels(t_data *data);
void				update_texture_pixels(t_data *data, t_txt *tex, t_ray *ray,
						int x);

//  -------------------------------------------------------------------------
// |								RENDER									|
// -------------------------------------------------------------------------

// srcs/render/render.c
void				set_image_pixel(t_img *image, int x, int y, int color);
void				render_images(t_data *data);
int					render(t_data *data);

// srcs/render/render_minimap.c
void				render_minimap(t_data *data);

// srcs/render/minimap_image.c
void				render_minimap_image(t_data *data, t_minimap *minimap);

// srcs/render/minimap_pixels.c
void				set_minimap_tile_pixels(t_minimap *minimap,
						int x, int y, int color);
void				set_circle_pixels(t_img *img, int x_center, int y_center,
						int radius);

// srcs/render/raycasting.c
int					raycasting(t_player *player, t_data *data);

//  -------------------------------------------------------------------------
// |								MOVE									|
// -------------------------------------------------------------------------

// srcs/move/inputs.c
void				inputs(t_data *data);

// srcs/move/player_move.c
int					move_player(t_data *data);

// srcs/move/player_pos.c
int					validate_move(t_data *data, double new_x, double new_y);

// srcs/move/player_rotate.c
int					rotate_player(t_data *data, double rotdir);

// srcs/move/player_dir.c
void				init_player_direction(t_data *data);

//  -------------------------------------------------------------------------
// |								DEBUG									|
// -------------------------------------------------------------------------

// srcs/parsing/debug.c
void				print_data(t_data *data);
void				print_tab(char **tab);
void				debug_display_minimap(t_minimap *minimap);

//  -------------------------------------------------------------------------
// |								EXIT									|
// -------------------------------------------------------------------------

// srcs/exit/clean.c
void				clean_program(t_data *data);
void				destroy_window(t_data *data);

// srcs/exit/clean_utils.c
void				free_tab(void **tab);
void				free_ptr(void *ptr);

// srcs/exit/error.c
void				check_alloc(t_data *data, void *ptr, char *err_msg);
void				error_msg(char *error_type, char *usage);
void				error_exit(char *str, t_data *data);
int					exit_game(t_data *data, int status);

#endif

#include "../inc/so_long.h"

static void init_vars(t_game *game)
{
	game->map_size.x = ft_strlen(game->map[0]);
	game->map_size.y = get_height(game->map);
	game->nb_collectible = 0;
}

int key_check(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		end_game("", game, event_end, NULL);
	else if (keycode == XK_a || keycode == XK_Left)
	{
		move_left(game);
	}
	else if (keycode == XK_d || keycode == XK_Right)
		move_right(game);
	else if (keycode == XK_w || keycode == XK_Up)
		move_up(game);
	else if (keycode == XK_s || keycode == XK_Down)
		move_down(game);
	return (0);
}

void init_game(t_game *game, char *map_file)
{
	(void)map_file;
	game->map = get_map(map_file, game);
	if (game->map != NULL)
	{
		show_table(game->map);
		init_vars(game);
		check_map_valid(game, map_file);
		// ft_printf("Completed check-in, we can start now!\nControls :\nArrows : up, left, down, right.\nKeyboard : W,A,S,D.\nESC to quit.\n");
		game->mlx_ptr = mlx_init();
		if (!game->mlx_ptr)
			end_game("Falling mlx_init(). Aborting, bye.", game, map_error, NULL);
		game->mlx_win = mlx_new_window(game->mlx_ptr, game->map_size.x  * 50, game->map_size.y * 50, "Event Parameters");
		if (!game->mlx_win)
			end_game("Falling mlx_new_window(). Aborting, bye.", game, map_error, game->mlx_ptr);
		render_map(game);
		ft_printf("position rick : x = %d  y = %d\n", game->p_pos.x, game->p_pos.y);
		mlx_hook(game->mlx_win, KEY_RELEASED, KEY_RELEASED_MASK, key_check, game);
		mlx_hook(game->mlx_win, ON_DESTROY, NO_EVENT_MASK, exit_event, game);
		mlx_loop(game->mlx_ptr);
	}
	end_game("Invalid file! An error occurred while saving the map in game->map. Aborting, bye!", game, file_error, NULL);
}
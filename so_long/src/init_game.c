#include "../inc/so_long.h"

static void init_vars(t_game *game)
{
	game->win_w = ft_strlen(game->map[0]);
	game->win_h = get_height(game->map);
}

int key_check(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		end_game("", game, event_end);
	else if (keycode == XK_a || keycode == XK_Left)
		ft_printf("left !\n");
	else if (keycode == XK_d || keycode == XK_Right)
		ft_printf("right !\n");
	else if (keycode == XK_w || keycode == XK_Up)
		ft_printf("up !\n");
	else if (keycode == XK_s || keycode == XK_Down)
		ft_printf("down !\n");
	// 	ft_printf("code : %d\n", keycode);
	return (0);
}

void init_game(t_game *game, char *map_file)
{
	(void)map_file;
	get_map(map_file, game);
	if (game->map != NULL)
	{
		check_map_rect(game);
		check_map_walls(game);
		check_map_elem(game);
		ft_printf("Completed check-in, we can start now!\nControls :\nArrows : up, left, down, right.\nKeyboard : W,A,S,D.\nESC to quit.\n");
		init_vars(game);
		game->mlx_ptr = mlx_init();
		game->mlx_win = mlx_new_window(game->mlx_ptr, game->win_w * 50, game->win_h * 50, "Event Parameters");
		show_table(game);
		render_map(game);
		mlx_hook(game->mlx_win, KEY_RELEASED, KEY_RELEASED_MASK, key_check, game);
		mlx_hook(game->mlx_win, ON_DESTROY, NO_EVENT_MASK, exit_event, game);
		mlx_loop(game->mlx_ptr);
	}
}
#include "../inc/so_long.h"
#include "mlx.h"
// #include "../libft/ft_printf.c"


int	exit_event(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	return (0);
}

static void	init_game(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx_ptr, 640, 360, "Event Parameters");
	mlx_hook(game->mlx_win, 17, 0, exit_event, &game);
	mlx_loop(game->mlx_ptr);
}



int	main(void)
{
	t_game game;
	init_game(&game);
	return (0);
}
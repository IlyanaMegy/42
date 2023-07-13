#include "../inc/so_long.h"
#include "mlx.h"
// #include "../libft/ft_printf.c"

static void	init_game(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx_ptr, 640, 360, "Event Parameters");
	mlx_loop(game->mlx_ptr);
}

int	main(int ac, char **av)
{
	t_game game;
	if (ac == 1 && av[0])
	{
		init_game(&game);
	}
	// ft_printf("running %s\n", av[0]);
	return (0);
}
#include "mlx.h"

int	main(void)
{
	void *mlx_ptr;
	void *game_win_ptr;

	mlx_ptr = mlx_init();
	game_win_ptr = mlx_new_window(mlx_ptr, 1000, 545, "game_on");
	mlx_loop(mlx_ptr);
	return (0);
}
#include "../inc/libft.h"
#include "../inc/so_long.h"
#include "mlx.h"

void	destroy_the(t_game *game)
{
	// mlx_destroy_image(game->mlx_pointer, game->wall.ptr);
	// mlx_destroy_image(game->mlx_pointer, game->floor.ptr);
	// mlx_destroy_image(game->mlx_pointer, game->portal.ptr);
	// [...]
	mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	mlx_destroy_display(game->mlx_ptr);
	// free_map(game);
	free(game->mlx_ptr);
	return ;
}

void	end_game(char *msg, t_game *game, enum e_state state)
{
	if (state == event_end)
	{
		ft_printf("%s\n", msg);
		destroy_the(game);
		exit(0);
		return ;
	}
	ft_printf("Error\n%s\n" RED, msg);
	destroy_the(game);
	exit(1);
	return ;
}

int	exit_event(t_game *game)
{
	end_game("closing the window...", game, event_end);
	return (0);
}

static void	init_hook(t_game *game, int event, int mask, int (*f)())
{
	mlx_hook(game->mlx_win, event, mask, f, game);
}

static void	init_game(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx_ptr, 640, 360, "Event Parameters");
	init_hook(game, ON_DESTROY, NO_EVENT_MASK, exit_event);
	mlx_loop(game->mlx_ptr);
}

int	main(void)
{
	t_game game;
	init_game(&game);
	return (0);
}
#include "../inc/so_long.h"

void	put_that_img(void *img, int x, int y, t_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, img, x * 50, y * 50);
}

void	move_to(int x, int y, t_game *game)
{
    put_that_img(game->bg_img, game->p_pos.x, game->p_pos.y, game);
	game->map[game->p_pos.y][game->p_pos.x] = '0';
	game->p_pos.y = y;
	game->p_pos.x = x;
	if (game->map[y][x] == 'C')
	{
		game->collected_items++;
		game->nb_collectible--;
	}
	put_that_img(game->rick_img, game->p_pos.x, game->p_pos.y, game);
	game->moves++;
	ft_printf("moves : %d\n", game->moves);
	if (game->map[y][x] == 'E')
		end_game("Congratulation you win!", game, game_over, NULL);
	game->map[y][x] = 'P';
	ft_printf("pos x = %d, y = %d\n", game->p_pos.x, game->p_pos.y);
	show_table(game->map);
}

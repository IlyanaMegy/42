#include "../inc/so_long.h"

void	put_that_img(void *img, int x, int y, t_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, img, x * 50, y * 50);
}

int	is_wall(t_game *game, int y, int x)
{
	return (game->map[y][x] == '1');
}

void	*change_main_dir(char *img_path, t_game *game)
{
	int	img_x;
	int	img_y;

	img_x = game->img_size.x;
	img_y = game->img_size.y;
	return (mlx_xpm_file_to_image(game->mlx_ptr, img_path, &img_x, &img_y));
}

void	move_to(int x, int y, char *img_path, t_game *game)
{
	if (game->map[y][x] == 'E' && game->nb_collectible != 0)
		return ;
	put_that_img(game->bg_img, game->p_pos.x, game->p_pos.y, game);
	game->map[game->p_pos.y][game->p_pos.x] = '0';
	game->p_pos.y = y;
	game->p_pos.x = x;
	if (game->map[y][x] == 'C')
		game->nb_collectible--;
	game->main_img = change_main_dir(img_path, game);
	put_that_img(game->main_img, game->p_pos.x, game->p_pos.y, game);
	game->moves++;
	ft_printf("moves : %d\n", game->moves);
	if (game->map[y][x] == 'E' && game->nb_collectible == 0)
		end_game("Congratulation you win!", game, event_end, NULL);
	game->map[y][x] = 'P';
	ft_printf("pos x = %d, y = %d\n", game->p_pos.x, game->p_pos.y);
	show_table(game->map);
}

#include "../inc/so_long.h"

int check_env(t_game *game, int x, int y)
{
    if (game->map[x][y] == '1')
        return 0;
    else if (game->map[x][y] == 'C')
        game->nb_collectible++;
    else if (game->map[x][y] == 'E')
        end_game("Congratulation you win!", game, game_over, NULL);
    return 1;
}

void move_left(t_game *game)
{
    if (check_env(game, game->p_pos.x - 1, game->p_pos.y))
    {
        mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->bg_img, game->p_pos.x * 50, game->p_pos.y * 50);
        game->p_pos.x -= 1;
        mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->rick_img, game->p_pos.x * 50, game->p_pos.y * 50);
    }
}

void move_right(t_game *game)
{
    if (check_env(game, game->p_pos.x + 1, game->p_pos.y))
    {
        mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->bg_img, game->p_pos.x * 50, game->p_pos.y * 50);
        game->p_pos.x += 1;
        mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->rick_img, game->p_pos.x * 50, game->p_pos.y * 50);
    }
}

void move_up(t_game *game)
{
    if (check_env(game, game->p_pos.x, game->p_pos.y - 1))
    {
        mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->bg_img, game->p_pos.x * 50, game->p_pos.y * 50);
        game->p_pos.y -= 1;
        mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->rick_img, game->p_pos.x * 50, game->p_pos.y * 50);
    }
}

void move_down(t_game *game)
{
    if (check_env(game, game->p_pos.x, game->p_pos.y + 1))
    {
        mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->bg_img, game->p_pos.x * 50, game->p_pos.y * 50);
        game->p_pos.y += 1;
        mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->rick_img, game->p_pos.x * 50, game->p_pos.y * 50);
    }
}
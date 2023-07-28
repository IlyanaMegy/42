#include "../inc/so_long.h"

void img_on_map(char p, int x, int y, t_game *g)
{
    if (p == '1')
        mlx_put_image_to_window(g->mlx_ptr, g->mlx_win, g->wall_img, x, y);
    else if (p == 'C')
        mlx_put_image_to_window(g->mlx_ptr, g->mlx_win, g->collec_img, x, y);
    else if (p == 'E')
        mlx_put_image_to_window(g->mlx_ptr, g->mlx_win, g->exit_img, x, y);
    else if (p == 'P')
    {
        g->y_p = y;
        g->x_p = x;
        mlx_put_image_to_window(g->mlx_ptr, g->mlx_win, g->main_img, x, y);
    }
    else
        mlx_put_image_to_window(g->mlx_ptr, g->mlx_win, g->bg_img, x, y);
}

void init_img(t_game *game)
{
    game->wall_img = mlx_xpm_file_to_image(game->mlx_ptr, "./img/wall.xpm", &game->img_size.x, &game->img_size.y);
    // game->wong_img = mlx_xpm_file_to_image(game->mlx_ptr, "./img/wong.xpm", &game->img_size.x, &game->img_size.y);
    game->main_img = mlx_xpm_file_to_image(game->mlx_ptr, "./img/down.xpm", &game->img_size.x, &game->img_size.y);
    game->exit_img = mlx_xpm_file_to_image(game->mlx_ptr, "./img/exit.xpm", &game->img_size.x, &game->img_size.y);
    game->collec_img = mlx_xpm_file_to_image(game->mlx_ptr, "./img/apple.xpm", &game->img_size.x, &game->img_size.y);
    game->bg_img = mlx_xpm_file_to_image(game->mlx_ptr, "./img/bg.xpm", &game->img_size.x, &game->img_size.y);
}

void render_map(t_game *game)
{
    int y;
    int x;
    int map_y;
    int map_x;
    int tmp_w;

    y = 0;
    map_y = 0;
    tmp_w = game->map_size.x;
    init_img(game);
    while (game->map_size.y > 0)
    {
        x = 0;
        map_x = 0;
        while (game->map_size.x > 0)
        {
            img_on_map(game->map[map_y][map_x], x, y, game);
            map_x++;
            x += 50;
            game->map_size.x--;
        }
        game->map_size.x = tmp_w;
        map_y++;
        y += 50;
        game->map_size.y--;
    }
}
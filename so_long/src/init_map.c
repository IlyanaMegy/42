#include "../inc/so_long.h"

char **get_map(char *map_file, t_game *game)
{
    char *curr;
    char *lines;
    int fd;
    char *tmp;

    fd = open(map_file, O_RDONLY);
    if (fd < 0){
        end_game("This file can't be read : error while trying opening.", game, file_error, NULL);
    }
    lines = get_next_line(fd);
    while (lines && lines[0] == '\n')
    {
        free(lines);
        lines = get_next_line(fd);
    }
    curr = get_next_line(fd);
    while (curr)
    {
        if (curr[0] == '\n')
        {
            free(curr);
            break;
        }
        tmp = lines;
        lines = ft_strjoin(lines, curr);
        free(tmp);
        free(curr);
        curr = get_next_line(fd);
    }
    close(fd);
    if (*lines == '\0')
        end_game("This file is empty!", game, file_error, lines);
    return (ft_split(lines, '\n'));
}

int get_height(char **map)
{
    int i;

    i = 0;
    while (map[i] != NULL)
        i++;
    return (i);
}

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
        mlx_put_image_to_window(g->mlx_ptr, g->mlx_win, g->rick_img, x, y);
    }
    else
        mlx_put_image_to_window(g->mlx_ptr, g->mlx_win, g->bg_img, x, y);
}

void init_img(t_game *game)
{
    game->wall_img = mlx_xpm_file_to_image(game->mlx_ptr, "./img/a1.xpm", &game->img_size.x, &game->img_size.y);
    //game->wong_img = mlx_xpm_file_to_image(game->mlx_ptr, "./img/wong.xpm", &game->img_size.x, &game->img_size.y);
    game->rick_img = mlx_xpm_file_to_image(game->mlx_ptr, "./img/rick.xpm", &game->img_size.x, &game->img_size.y);
    game->exit_img = mlx_xpm_file_to_image(game->mlx_ptr, "./img/exit.xpm", &game->img_size.x, &game->img_size.y);
    game->collec_img = mlx_xpm_file_to_image(game->mlx_ptr, "./img/bottle.xpm", &game->img_size.x, &game->img_size.y);
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
    tmp_w = game->map_size.x ;
    init_img(game);
    while (game->map_size.y > 0)
    {
        x = 0;
        map_x = 0;
        while (game->map_size.x  > 0)
        {
            img_on_map(game->map[map_y][map_x], x, y, game);
            map_x++;
            x += 50;
            game->map_size.x --;
        }
        game->map_size.x  = tmp_w;
        map_y++;
        y += 50;
        game->map_size.y--;
    }
}
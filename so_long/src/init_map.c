#include "../inc/so_long.h"

void get_map(char *map_file, t_game *game)
{
    char *curr;
    char *lines;
    int fd;

    curr = "";
    lines = ft_strdup("");
    fd = open(map_file, O_RDONLY);
    if (fd < 0)
        end_game("This file can't be read.", game, error);
    while (curr)
    {
        curr = get_next_line(fd);
        if (curr == NULL || curr[0] == '\n')
            break;
        lines = ft_strjoin(lines, curr);
        free(curr);
    }
    free(curr);
    close(fd);
    if (*lines == '\0')
        end_game("This file is empty!", game, error);
    game->map = ft_split(lines, '\n');
    return;
}

int get_height(char **map)
{
    int i;

    i = 0;
    while (map[i] != NULL)
        i++;
    return (i);
}

void img_here(t_game ***g, int x, int y, char *img_path)
{
    int img_w;
    int img_h;
    img_path = "./test.xpm";

    (**g)->img = mlx_xpm_file_to_image((**g)->mlx_ptr, img_path, &img_w, &img_h);
    ft_printf("ptr = %p, img = %d, res = %d\n", (char *)(**g)->mlx_ptr, (**g)->img, mlx_xpm_file_to_image((**g)->mlx_ptr, img_path, &img_w, &img_h));
    mlx_put_image_to_window((**g)->mlx_ptr, (**g)->mlx_win, (**g)->img, x, y);
}

void img_on_map(char p, int x, int y, t_game **g)
{
    if (p == '1')
    {
        ft_printf("ptr = %p, img = %d\n", (char *)(*g)->mlx_ptr, (*g)->img);
        img_here(&g, x, y, "../img/aste1.xpm");
    }
    else if (p == 'C')
    {
        img_here(&g, x, y, "../img/bottle.xpm");
    }
    else if (p == 'E')
    {
        img_here(&g, x, y, "../img/portal.xpm");
    }
    else if (p == 'P')
    {
        (*g)->y_p = y;
        (*g)->x_p = x;
        img_here(&g, x, y, "../img/main.xpm");
    }
    else
        img_here(&g, x, y, "../img/bg.xpm");
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
    tmp_w = game->win_w;
    while (game->win_h > 0)
    {
        x = 0;
        map_x = 0;
        while (game->win_w > 0)
        {
            ft_printf("game->map[%d][%d] = %c, x = %d, y = %d\nnext:\n", map_y, map_x, game->map[map_y][map_x], x, y);
            img_on_map(game->map[map_y][map_x], x, y, &game);
            map_x++;
            x += 100;
            ft_printf("game->map[%d][%d] = %c, x = %d, y = %d\n\n", map_y, map_x, game->map[map_y][map_x], x, y);
            game->win_w--;
        }
        game->win_w = tmp_w;
        map_y++;
        y += 100;
        game->win_h--;
    }
}
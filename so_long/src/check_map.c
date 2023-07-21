#include "../inc/so_long.h"

void is_map_playable(t_game *game, char *map_file)
{
    // int collec;
    // int exit_count;
    char **map_clone;

    map_clone = get_map(map_file, game);
    ft_printf("\n\tcloned map...\n\n");
    show_table(map_clone);
}

void check_map_rect(t_game *game)
{
    int y;
    int x;
    int height;
    int temp;

    y = 0;
    temp = 0;
    height = get_height(game->map);
    while (y != height)
    {
        x = 0;
        while (game->map[y][x] != '\0')
            x++;
        y++;
        if (temp != 0)
        {
            if (temp != x)
                end_game("This map is not rectangular!", game, map_error, NULL);
        }
        else
            temp = x;
    }
}

void check_map_walls(t_game *game)
{
    int i;

    if (check_line(game->map[0]))
        end_game("This map is not surrounded by walls! Check first line...", game, map_error, NULL);
    i = get_height(game->map) - 1;
    if (i <= 4 || ft_strlen(game->map[0]) <= 4)
        end_game("Too small map!", game, map_error, NULL);
    while (i)
    {
        if (game->map[i][0] != '1' || game->map[i][ft_strlen(game->map[i]) - 1] != '1')
            end_game("This map is not surrounded by walls!", game, map_error, NULL);
        i--;
    }
    if (check_line(game->map[get_height(game->map) - 1]))
        end_game("This map is not surrounded by walls! Check last line...", game, map_error, NULL);
}

void check_map_elem(t_game *game)
{
    t_game_map map;

    map.c = 0;
    map.p = 0;
    map.e = 0;
    map.y = get_height(game->map) - 1;
    while (map.y--)
    {
        map.x = 0;
        while (game->map[map.y][map.x] != '\0')
        {
            if (game->map[map.y][map.x] == 'E')
                map.e++;
            else if (game->map[map.y][map.x] == 'P')
                map.p++;
            else if (game->map[map.y][map.x] == 'C')
                map.c++;
            else if (game->map[map.y][map.x] != '1' &&
                     game->map[map.y][map.x] != '0')
                end_game("Unknown element found in the map.", game, map_error, NULL);
            map.x++;
        }
    }
    if (map.c == 0 || map.p == 0 || map.e == 0 || map.p > 1)
        end_game("One element is missing.", game, map_error, NULL);
    map.y = get_height(game->map);
}

// -----------------------------------------------------------------------
// DELETE THIS LATER
void show_table(char **map)
{
    int height = get_height(map) - 1;
    ft_printf("\n\tShowing map...\n\n");
    int y = 0;
    int x;

    while (y <= height)
    {
        x = 0;
        while (map[y][x] != '\0')
        {
            ft_printf("%c ", map[y][x]);
            x++;
        }
        y++;
        ft_printf("\n");
    }
    ft_printf("\n");
}
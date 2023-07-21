#include "../inc/so_long.h"

int check_line(char *line)
{
    int i;

    i = 0;
    while (line && line[i] != '\0')
    {
        if (line[i] != '1')
            return (1);
        i++;
    }
    return (0);
}

void	check_map_valid(t_game *game, char *map_file)
{
    t_game_map map;

    map.p = 0;
    map.e = 0;
    map.y = game->map_size.y - 1;
	check_map_rect(game);
	check_map_walls(game);
	check_map_elem(game, &map);
    is_map_playable(game, map_file);
}

int to_find(char *str, char c)
{
    while (*str)
    {
        if (*str == c)
            return 1;
        str++;
    }
    return 0;
}
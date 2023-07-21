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
	check_map_rect(game);
	check_map_walls(game);
	check_map_elem(game);
    is_map_playable(game, map_file);
}
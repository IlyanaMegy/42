#include "../inc/so_long.h"

void unknown_element(t_game **game)
{
    int x;

    x = 0;
    while ((*game)->map[x])
    {
        free((*game)->map[x]);
        x++;
    }
    free((*game)->map);
    end_game("Unknown element found", *game, file_error);
}

int check_line(char *line)
{
    int i;

    i = 0;
    while (line[i] != '\0')
    {
        if (line[i] != '1')
            return (1);
        i++;
    }
    return (0);
}
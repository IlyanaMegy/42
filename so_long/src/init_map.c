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
    if (*lines =='\0')
        end_game("This file is empty!", game, error);
    game->map = ft_split(lines, '\n');
    return;
}
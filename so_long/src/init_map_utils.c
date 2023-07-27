#include "../inc/so_long.h"

void join_me(char **lines, char **curr)
{
    char *tmp;

    tmp = *lines;
    *lines = ft_strjoin(*lines, *curr);
    free(tmp);
    free(*curr);
}

void pass_empty_lines(char **lines, int *fd)
{
    *lines = get_next_line(*fd);
    while (*lines && *lines[0] == '\n')
    {
        free(*lines);
        *lines = get_next_line(*fd);
    }
}

char **get_map(char *map_file, t_game *game)
{
    char *curr;
    char *lines;
    int fd;

    fd = open(map_file, O_RDONLY);
    if (fd < 0)
        end_game("This file can't be read : error while trying opening.", game, file_error, NULL);
    pass_empty_lines(&lines, &fd);
    curr = get_next_line(fd);
    while (curr)
    {
        if (curr[0] == '\n')
        {
            free(curr);
            break;
        }
        join_me(&lines, &curr);
        curr = get_next_line(fd);
    }
    close(fd);
    if (*lines == '\0')
        end_game("This file is empty!", game, file_error, lines);
    return (ft_split(lines, '\n'));
}
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

int	get_height(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}

// c = game->map[map.y][map.x]
char	*unknown_element(t_game **game)
{
	int	x;

	x = 0;
	while ((*game)->map[x])
	{
		free((*game)->map[x]);
		x++;
	}
	free((*game)->map);
	end_game("Unknown element found", *game, file_error);
	exit(1);
}
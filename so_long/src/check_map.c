#include "../inc/so_long.h"

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
                end_game("This map is not rectangular!", game, file_error);
        }
        else
            temp = x;
    }
}

void check_map_walls(t_game *game)
{
    int i;
    char *err;

    err = "This map is not surrounded by walls!";
    if (check_line(game->map[0]))
        end_game(err, game, file_error);
    i = get_height(game->map) - 1;
    while (i)
    {
        if (game->map[i][0] != '1' || game->map[i][ft_strlen(game->map[i] - 1)] != '1')
            end_game(err, game, file_error);
        i--;
    }
    if (check_line(game->map[get_height(game->map) - 1]))
        end_game(err, game, file_error);
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
                unknown_element(&game);
            map.x++;
        }
    }
    if (map.c == 0 || map.p == 0 || map.e == 0 || map.p > 1)
        end_game("One element is missing.", game, file_error);
}

// int is_playable(t_game *game)
// {
//     int collec;
//     int exit_count;

//     collec = 0;
//     exit_count = 0;


// }




// -----------------------------------------------------------------------
// DELETE THIS LATER 
void show_table(t_game *game)
{
    int height = get_height(game->map) - 1;
	ft_printf("\n\tShowing map...\n\n");
	int y = 0;
	int x;
	
    while (y <= height)
    {
        x = 0;
        while (game->map[y][x] != '\0')
        {
			ft_printf("%c ", game->map[y][x]);
			x++;
		}
		y++;
		ft_printf("\n");
	}
	ft_printf("\n");
}
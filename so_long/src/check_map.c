#include "../inc/so_long.h"

int fill(char **map, t_vector size, t_vector cur, char *elements)
{
    static int elem_count = 0;
    if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x || !to_find(elements, map[cur.y][cur.x]))
        return elem_count;
    if (map[cur.y][cur.x] == 'C' || map[cur.y][cur.x] == 'E')
        elem_count++;
    map[cur.y][cur.x] = 'X';
    fill(map, size, (t_vector){cur.x - 1, cur.y}, elements);
    fill(map, size, (t_vector){cur.x + 1, cur.y}, elements);
    fill(map, size, (t_vector){cur.x, cur.y - 1}, elements);
    fill(map, size, (t_vector){cur.x, cur.y + 1}, elements);
    return elem_count;
}

void is_map_playable(t_game *game, char *map_file)
{
    char **map_clone;
    int collected_items;
    char *catch_me;

    map_clone = get_map(map_file, game);
    collected_items = 0;
    catch_me = "PCE0";
    if (map_clone != NULL)
    {
        // ft_printf("\n\tcloned map...");
        // show_table(map_clone);
        collected_items = fill(map_clone, game->map_size, game->p_pos, catch_me);
        // show_table(map_clone);
        free_map(map_clone);
        if (collected_items != game->nb_collectible + 1)
            end_game("Unplayable map. Aborting, bye!", game, map_error, NULL);
        // ft_printf("all is good we can continue!\n");
        return ;
    }
    end_game("Invalid file! An error occurred while saving the map in map_clone. Aborting, bye!", game, map_error, NULL);
}

void check_map_rect(t_game *game)
{
    int y;
    int x;
    int height;
    int temp;

    y = 0;
    temp = 0;
    height = game->map_size.y;
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
    i = game->map_size.y - 1;
    if (i <= 4 || ft_strlen(game->map[0]) <= 4)
        end_game("Too small map!", game, map_error, NULL);
    while (i)
    {
        if (game->map[i][0] != '1' || game->map[i][ft_strlen(game->map[i]) - 1] != '1')
            end_game("This map is not surrounded by walls!", game, map_error, NULL);
        i--;
    }
    if (check_line(game->map[game->map_size.y - 1]))
        end_game("This map is not surrounded by walls! Check last line...", game, map_error, NULL);
}

void check_map_elem(t_game *game, t_game_map *map)
{
    while (map->y--)
    {
        map->x = 0;
        while (game->map[map->y][map->x] != '\0')
        {
            if (game->map[map->y][map->x] == 'E')
                map->e++;
            else if (game->map[map->y][map->x] == 'P')
            {
                map->p++;
                game->p_pos.x = map->x;
                game->p_pos.y = map->y;
            }
            else if (game->map[map->y][map->x] == 'C')
                game->nb_collectible++;
            else if (game->map[map->y][map->x] != '1' && game->map[map->y][map->x] != '0')
                end_game("Unknown element found in the map.", game, map_error, NULL);
            map->x++;
        }
    }
    if (game->nb_collectible < 1 || map->p != 1 || map->e != 1)
        end_game("Wrong number of elements", game, map_error, NULL);
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
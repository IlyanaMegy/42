
#include "flood_fill.h"

int	element(char *elements, char c)
{
	while(*elements)
	{
		if (*elements == c)
			return 1;
		elements++;
	}
	return 0;
}

void	fill(char **tab, t_point size, t_point cur, char *to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| !element(to_fill, tab[cur.y][cur.x]))
		return ;
	tab[cur.y][cur.x] = 'X';
	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	char *catch_me = "PCE0";
	fill(tab, size, begin, catch_me);
}


#include <stdlib.h>
#include <stdio.h>

char	**make_area(char **zone, t_point size)
{
	char	**new;

	new = malloc(sizeof(char *) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}
	return (new);
}

int	main(void)
{
	// char	**zone;
	t_point	size;
	t_point	begin;

	size.x = 8;
	size.y = 5;
	begin.x = 1;
	begin.y = 2;
	char	*zone[] = {
		"11111111",
		"10C01001",
		"1P0000E1",
		"10110001",
		"11111111",
	};

	char **area = make_area(zone, size);

	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");

	flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	return (0);
}
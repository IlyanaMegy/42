#include "../include/so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

void	free_tab(char **tab, int until)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (i < until)
	{
		free(tab[i]);
		i++;
	}
	if (until == 0)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
	}
	free(tab);
}

char	*get_next_line(int fd, int *error)
{
	int		i;
	int		rd;
	char	character;
	char	*buffer;

	i = 0;
	rd = 0;
	buffer = malloc(100000);
	if (!buffer)
		return (*error = 1, NULL);
	rd = read(fd, &character, 1);
	while (rd > 0)
	{
		buffer[i++] = character;
		if (character == '\n')
			break ;
		rd = read(fd, &character, 1);
	}
	buffer[i] = '\0';
	if (rd == -1)
		return (*error = 1, free(buffer), NULL);
	if (i == 0 || (!buffer[i - 1] && !rd))
		return (free(buffer), NULL);
	return (buffer);
}

int	ft_strlen_param(char *str, char c, int *error)
{
	int	i;

	i = 0;
	if (!str)
		return (*error = 1, 0);
	while (*str != c && *str != '\0')
	{
		str++;
		i++;
	}
	return (i);
}

int	number_line(char **map)
{
	int	size;

	size = 0;
	while (map[size])
		size++;
	return (size);
}
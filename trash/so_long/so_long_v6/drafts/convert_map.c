int	info_map_2(int fd, char *str, int *error)
{
	while (str && str[0] == '\n')
	{
		free(str);
		str = get_next_line(fd, error);
	}
	if (!str && *error == 0)
		return (free(str), 0);
	return (write(2, "Error\nFile is empty", 19), close(fd), free(str), -1);
}

int	info_map(char *pathname, int *number_of_line, int *number_of_char)
{
	int		fd;
	char	*str;
	int		error;

	error = 0;
	fd = open(pathname, O_RDONLY);
	if (fd == -1)
		return (write(2, "Error\nFile map is not readable", 26), -1);
	str = get_next_line(fd, &error);
	while (str && str[0] == '\n')
	{
		free(str);
		str = get_next_line(fd, &error);
	}
	*number_of_char = ft_strlen_param(str, '\n', &error);
	while (str && str[0] != '\n')
	{
		*number_of_line = *number_of_line + 1;
		if (*number_of_char != ft_strlen_param(str, '\n', &error))
			return (write(2, "Error\nInvalid map (not rectangular)", 36),
					close(fd),
					free(str),
					-1);
		free(str);
		str = get_next_line(fd, &error);
	}
	return (info_map_2(fd, str, &error));
}

char	**malloc_map(char *pathname)
{
	int		number_of_line;
	int		number_of_char;
	int		i;
	char	**map;

	number_of_char = 0;
	number_of_line = 0;
	i = 0;
	if (info_map(pathname, &number_of_line, &number_of_char))
		return (NULL);
	map = malloc((number_of_line + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	while (number_of_line > i)
	{
		map[i] = malloc((number_of_char + 1) * sizeof(char));
		if (!map[i])
			return (free_tab(map, i), NULL);
		i++;
	}
	return (map);
}

char	**fill_map_2(char *str, char **map, int fd, int *error)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str && str[0] != '\n')
	{
		while (str[j] != '\n' && str[j] != '\0')
		{
			map[i][j] = str[j];
			j++;
		}
		map[i][j] = '\0';
		i++;
		j = 0;
		free(str);
		str = get_next_line(fd, error);
	}
	if (!str && *error == 1)
		return (close(fd), NULL);
	free(str);
	map[i] = NULL;
	close(fd);
	return (map);
}

char	**fill_map(char *pathname)
{
	char **map;
	int fd;
	char *str;
	int error;

	error = 0;
	if (!valid_ext_map(pathname))
		return (write(2, "Error\nInvalid extension (.ber)", 31), NULL);
	map = malloc_map(pathname);
	if (!map)
		return (NULL);
	fd = open(pathname, O_RDONLY);
	if (fd < 0)
		return (NULL);
	str = get_next_line(fd, &error);
	while (str && str[0] == '\n')
	{
		free(str);
		str = get_next_line(fd, &error);
	}
	return (fill_map_2(str, map, fd, &error));
}
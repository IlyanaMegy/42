#include "../inc/pushswap.h"

char	**get_array_single_arg(char *av)
{
	char	**array;

	array = ft_split(av, ' ');
	return (array);
}

char	**get_array_multiple_args(int ac, char **av)
{
	char			**array;
	unsigned int	i;

	array = malloc(sizeof(*array) * ((ac - 1) + 1));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (i < ((unsigned int)ac - 1))
	{
		array[i] = ft_strdup(av[i + 1]);
		if (array[i] == NULL)
		{
			free_double_ptr_char(array);
			return (NULL);
		}
		i++;
	}
	array[i] = NULL;
	return (array);
}

char	**get_array(int ac, char **av)
{
	char	**array;

	if (ac == 2)
		array = get_array_single_arg(av[1]);
	else
		array = get_array_multiple_args(ac, av);
	if (array == NULL || *array == NULL)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		exit (EXIT_FAILURE);
	}
	return (array);
}

int	*convert_to_int(char **array)
{
	int				*array_int;
	unsigned int	i;
	unsigned int	size;

	size = 0;
	while (array[size])
		size++;
	array_int = malloc(sizeof(*array_int) * size);
	if (array_int == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		array_int[i] = ft_atoi(array[i]);
		i++;
	}
	return (array_int);
}
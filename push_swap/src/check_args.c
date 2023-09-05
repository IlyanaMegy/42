#include "../inc/pushswap.h"

void	check_formats(char **array)
{
	int	i;
	int	j;

	i = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			while (array[i][j] == 32)
				j++;
			if ((array[i][j] == '+' || array[i][j] == '-'))
				j++;
			if (!ft_isdigit(array[i][j]))
				end_n_free(array, "Error\n", 1);
			while (ft_isdigit(array[i][j]))
				j++;
			if (array[i][j] != '\0')
				end_n_free(array, "Error\n", 1);
		}
		i++;
	}
}

int	check_args(int ac, char **av, size_t *s)
{
	char	**array;
	int *array_int;

	*s = 0;
	array = get_array(ac, av);
	check_formats(array);
	*s = 0;
	while (array[*s])
		(*s)++;
	print_double_array(array);
	array_int = convert_to_int(array);
	if (array_int == NULL)
		end_n_free(array, "", 1);
	return (0);
}
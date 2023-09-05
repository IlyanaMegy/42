#include "../inc/pushswap.h"
#include "../inc/libft.h"


static int	check_duplicate(int *array, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	counter;

	i = 0;
	while (i < size)
	{
		j = 0;
		counter = 0;
		while (j < size)
		{
			if (array[i] == array[j])
				counter++;
			j++;
		}
		if (counter != 1)
			return (1);
		i++;
	}
	return (0);
}

int	check_intlim(char **array)
{
	size_t		i;
	size_t		j;
	size_t		lenght;
	long int	conv;

	i = 0;
	j = 0;
	while (array[i])
	{
		j = 0;
		lenght = 0;
		if (array[i][j] == '+' || array[i][j] == '-')
			j++;
		while (array[i][j] == '0')
			j++;
		while (ft_isdigit(array[i][j]))
		{
			lenght++;
			j++;
		}
		conv = ft_atol(array[i]);
		if (lenght > 10 || conv > INT_MAX || conv < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

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

int	*check_args(int ac, char **av, size_t *s)
{
	char **array;
	int *array_int;

	array = get_array(ac, av);
	check_formats(array);
	*s = 0;
	while (array[*s])
		(*s)++;
	array_int = convert_to_int(array);
	if (array_int == NULL)
		end_n_free(array, "", 1);
	if (check_intlim(array) || check_duplicate(array_int, *s))
	{
		free(array_int);
		end_n_free(array, "Error\n", 1);
	}
	free_double_char(array);
	return (array_int);
}
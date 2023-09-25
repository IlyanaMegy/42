/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 11:02:43 by ilymegy           #+#    #+#             */
/*   Updated: 2023/09/24 11:02:45 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"
#include "../inc/libft.h"

static int	check_duplicate(int *arr, size_t size)
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
			if (arr[i] == arr[j])
				counter++;
			j++;
		}
		if (counter != 1)
			return (1);
		i++;
	}
	return (0);
}

int	check_intlim(char **arr)
{
	size_t	i;
	size_t	j;
	size_t	l;

	i = 0;
	j = 0;
	while (arr[i])
	{
		j = 0;
		l = 0;
		if (arr[i][j] == '+' || arr[i][j] == '-')
			j++;
		while (arr[i][j] == '0')
			j++;
		while (ft_isdigit(arr[i][j]))
		{
			l++;
			j++;
		}
		if (l > 10 || ft_atol(arr[i]) > INT_MAX || ft_atol(arr[i]) < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

void	check_formats(char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			while (arr[i][j] == 32)
				j++;
			if ((arr[i][j] == '+' || arr[i][j] == '-'))
				j++;
			if (!ft_isdigit(arr[i][j]))
				end_n_free(arr, "Error\n", 1);
			while (ft_isdigit(arr[i][j]))
				j++;
			if (arr[i][j] != '\0')
				end_n_free(arr, "Error\n", 1);
		}
		i++;
	}
}

int	*check_args(int ac, char **av, size_t *s)
{
	char	**arr;
	int		*array_int;

	arr  = get_array(ac, av);
	if (arr == NULL)
		return (0);
	check_formats(arr);
	*s = 0;
	while (arr[*s])
		(*s)++;
	array_int = convert_to_int(arr);
	if (array_int == NULL)
		end_n_free(arr, "", 1);
	if (check_intlim(arr) || check_duplicate(array_int, *s))
	{
		free(array_int);
		end_n_free(arr, "Error\n", 1);
	}
	free_double_char(arr);
	return (array_int);
}

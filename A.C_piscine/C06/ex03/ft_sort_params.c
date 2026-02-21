/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:25:44 by ilymegy           #+#    #+#             */
/*   Updated: 2023/02/21 12:25:47 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int				i;
	char			diff;
	unsigned char	*s1u;
	unsigned char	*s2u;

	s1u = (unsigned char *)s1;
	s2u = (unsigned char *)s2;
	i = 0;
	diff = 0;
	while (s1u[i] && s2u[i])
	{
		diff = s1u[i] - s2u[i];
		i++;
		if (diff != 0)
			return (diff);
	}
	diff = s1u[i] - s2u[i];
	return (diff);
}

void	print_this(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_strswap(char **a, char **b)
{
	char	*c;

	c = *a;
	*a = *b;
	*b = c;
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc > 1)
	{
		i = 1;
		while (i++, argv[i])
		{
			j = 1;
			while (j++, argv[j - 1])
				if (argv[j - 1] && argv[j] && (ft_strcmp(argv[j - 1],
							argv[j]) > 0))
					ft_strswap(&argv[j - 1], &argv[j]);
		}
		i = 1;
		while (argv[i])
		{
			print_this(argv[i]);
			write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}

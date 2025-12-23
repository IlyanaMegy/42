/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:08:43 by ilymegy           #+#    #+#             */
/*   Updated: 2023/02/21 11:08:46 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	print_str(char *str)
{
	int	n;

	n = 0;
	while (str[n] != '\0')
	{
		write(1, &str[n], 1);
		++n;
	}
}

int	main(int argc, char *argv[])
{
	char	*filename;

	if (argc >= 1)
	{
		filename = argv[0];
		print_str(filename);
	}
	return (0);
}

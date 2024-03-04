/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:59:21 by ilymegy           #+#    #+#             */
/*   Updated: 2023/11/22 09:59:23 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	int	i;
	int	j;

	if (ac > 1)
	{
		for (i = 1; i < ac; i++)
		{
			for (j = 0; av[i][j] != '\0'; j++)
				av[i][j] = (char)toupper(av[i][j]);
			std::cout << av[i];
		}
		std::cout << std::endl;
		return (0);
	}
	std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}

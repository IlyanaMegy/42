/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:04:02 by ilymegy           #+#    #+#             */
/*   Updated: 2024/10/30 18:04:05 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	std::cout << std::endl;

	if (argc < 2)
		std::cout << YLLW "Usage: ./convert <value_to_cast1> <value_to_cast2> ..." RESET << std::endl;
	
	int	i = 1;
	
	while (argv[i])
	{
		std::cout << GRY1 "############## OUTPUT " << i << " ##############" RESET << std::endl;
		std::cout << ITAL GRY1 "user input:\t\"" << argv[i] << "\"\n" RESET << std::endl;

		if (argv[i][0])
			ScalarConverter::convert(argv[i++]);
		else
			std::cout << RUBY "Argument " << i++ << " is empty." RESET << std::endl;
		std::cout << std::endl;
	}
	return (0);
}

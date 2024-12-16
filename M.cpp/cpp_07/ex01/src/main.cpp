/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:32:25 by ilymegy           #+#    #+#             */
/*   Updated: 2024/11/26 16:32:26 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/style.hpp"
#include "../inc/iter.hpp"
#include <string>
#include <vector>

template <typename T1>
void	printer(T1 const &value)
{
	std::cout << value << "  |  ";
}

int	main(void)
{
	std::cout << CLRALL;

	int			intArray[] = {1, 2, 3, 4};
	double		dblArray[] = {4.4, 3.3, 2.2, 1.1};
	bool		bolArray[] = {true, false};
	char		chrArray[] = {'a', 'b', 'c', 'd', 'e'};
	std::string	strArray[] = {"string1", "string2", "string3"};
	std::vector<int> vec;

	std::cout << GRY1 "  ITER WITH INT ARRAY" << std::endl;
	std::cout << "****************************************" CYAN << std::endl << "|  ";
	iter(intArray, sizeof(intArray) / sizeof(int) , printer<const int>);
	std::cout << RESET << std::endl << std::endl;

	std::cout << GRY1 "  ITER WITH DOUBLE ARRAY" << std::endl;
	std::cout << "****************************************" LIME << std::endl << "|  ";
	iter(dblArray, sizeof(dblArray) / sizeof(double) , printer);
	std::cout << RESET << std::endl << std::endl;

	std::cout << GRY1 "  ITER WITH BOOL ARRAY" << std::endl;
	std::cout << "****************************************" GOLD << std::endl << "|  ";
	iter(bolArray, sizeof(bolArray) / sizeof(bool) , printer);
	std::cout << RESET << std::endl << std::endl;

	std::cout << GRY1 "  ITER WITH CHAR ARRAY" << std::endl;
	std::cout << "****************************************" RED1 << std::endl << "|  ";
	iter(chrArray, sizeof(chrArray) / sizeof(char) , printer);
	std::cout << RESET << std::endl << std::endl;

	std::cout << GRY1 "  ITER WITH STRING ARRAY" << std::endl;
	std::cout << "****************************************" PURP << std::endl << "|  ";
	iter(strArray, 3 , printer);
	std::cout << RESET << std::endl << std::endl;

	std::cout << GRY1 "  ITER WITH VECTOR ARRAY" << std::endl;
	std::cout << "****************************************" ORNG << std::endl << "|  ";
	for (int i = 0; i < 5; i++)
		vec.push_back((i + 1) * 2);
	iter(&vec[0], vec.size(), printer);
	std::cout << RESET << std::endl << std::endl;

	return (0);
}

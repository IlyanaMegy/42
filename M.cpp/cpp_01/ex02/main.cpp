/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:05:49 by ilymegy           #+#    #+#             */
/*   Updated: 2024/03/11 12:05:50 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "str address \t\t\t=\t" << &str << std::endl;
	std::cout << "stringPTR address \t\t=\t" << stringPTR << std::endl;
	std::cout << "stringREF address \t\t=\t" << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << "Value of str \t\t\t=\t" << str << std::endl;
	std::cout << "Value pointed of stringPTR \t=\t" << *stringPTR << std::endl;
	std::cout << "Value pointed of stringREF \t=\t" << stringREF << std::endl;
	return (0);
}

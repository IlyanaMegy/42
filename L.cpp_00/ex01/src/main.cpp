/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:49:11 by ilymegy           #+#    #+#             */
/*   Updated: 2024/03/04 17:49:13 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Contact.hpp"
#include "../inc/PhoneBook.hpp"

int	main(void)
{
	PhoneBook PhoneBook;
	bool run = true;
	std::string command;

	PhoneBook.show_instruction();
	std::cout << "\033[33m$>\033[0m";
	while (run && std::getline(std::cin, command))
	{
		if (std::cin.eof() == true)
		{
			std::cout << "You pressed ^D, Bye." << std::endl;
			exit(0);
		}
		else if (command.compare("ADD") == 0)
			PhoneBook.set_infos();
		else if (command.compare("SEARCH") == 0)
			PhoneBook.get_infos();
		else if (command.compare("EXIT") == 0)
		{
			std::cout << "Bye." << std::endl;
			run = false;
			continue ;
		}
		command.clear();
		PhoneBook.show_instruction();
		std::cout << "\033[33m$>\033[0m";
	}
	if (run)
		std::cout << "You pressed ^D, Bye." << command << std::endl;
	return (0);
}
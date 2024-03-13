/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:14:03 by ilymegy           #+#    #+#             */
/*   Updated: 2024/03/12 16:14:04 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

Harl::Harl(void)
{
	functions[0] = &Harl::debug;
	functions[1] = &Harl::info;
	functions[2] = &Harl::warning;
	functions[3] = &Harl::error;
	levelMap["debug"] = 0;
	levelMap["info"] = 1;
	levelMap["warning"] = 2;
	levelMap["error"] = 3;
	std::cout << "Harl is about to open his mouth." << std::endl;
}

Harl::~Harl(void)
{
	std::cout << "Harl shut the fuck up." << std::endl;
}

void Harl::complain(std::string level)
{
	std::map<std::string, int>::iterator i = levelMap.find(level);
	if (i == levelMap.end())
		std::cout << "Unknown level:\t" << level << std::endl;
	else
		switch (i->second)
		{
		case 0:
			(this->*functions[0])();
		case 1:
			(this->*functions[1])();
		case 2:
			(this->*functions[2])();
		case 3:
			(this->*functions[3])();
			break ;
		default:
			break ;
		}
}
void Harl::debug(void)
{
	std::cout << "DEBUG" << std::endl;
}

void Harl::info(void)
{
	std::cout << "INFO" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "WARNING" << std::endl;
}

void Harl::error(void)
{
	std::cout << "ERROR" << std::endl;
}

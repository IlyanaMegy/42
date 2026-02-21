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
	std::cout << "Harl is about to open his mouth." << std::endl;
}

Harl::~Harl(void)
{
	std::cout << "Harl shut the fuck up." << std::endl;
}

void Harl::complain(std::string level)
{
	void (Harl::*functions[4])() = {&Harl::debug, &Harl::info, &Harl::warning,
		&Harl::error};
	std::string states[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	int i;
	for (i = 0; i < 4; i++)
	{
		if (level == states[i])
		{
			(this->*functions[i])();
			return ;
		}
	}
	if (i == 4)
		std::cout << "Unknown level:\t" << level << std::endl;
}
void Harl::debug(void)
{
	std::cout << "DEBUG:\t\tor don't idc..." << std::endl;
}

void Harl::info(void)
{
	std::cout << "INFO:\t\tit's only informative information." << std::endl;
}

void Harl::warning(void)
{
	std::cout << "WARNING:\t/!\\" << std::endl;
}

void Harl::error(void)
{
	std::cout << "ERROR:\t\t404" << std::endl;
}

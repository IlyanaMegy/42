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

Harl::Harl()
{
	std::cout << "Harl shut the fuck up." << std::endl;
}

Harl::~Harl()
{
	std::cout << "Harl is about to open his mouth." << std::endl;
}

void Harl::complain(std::string level)
{
	std::map<std::string, int>::iterator i = levelDico.find(level);
	if (i != levelDico.end())
	{
		int idx = i->second;
		(this->*functions[idx])();
	}
	else
		std::cout << "Unknown level: " << level << std::endl;
}
void Harl::debug(void)
{
	std::cout << "DEBUG: Everything looks fine." << std::endl;
}

void Harl::info(void)
{
	std::cout << "INFO: Just an informative message." << std::endl;
}

void Harl::warning(void)
{
	std::cout << "WARNING: This might be a problem." << std::endl;
}

void Harl::error(void)
{
	std::cout << "ERROR: Something went wrong!" << std::endl;
}

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
	int	idx = -1;

	std::map<std::string, int>::iterator i = levelMap.find(level);
	if (i != levelMap.end())
	{
		idx = i->second;
		if (idx >=0 && idx <= 3)
			(this->*functions[idx])();
		else
            std::cout << "Invalid index:\t" << idx << std::endl;
	}
	else
		std::cout << "Unknown level:\t" << level << std::endl;
}
void Harl::debug(void)
{
	std::cout << "DEBUG:\t\tI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << std::endl;
}

void Harl::info(void)
{
	std::cout << "INFO:\t\tI cannot believe adding extra bacon costs more money. You did not put\
enough bacon in my burger ! If you did, I would not be asking for more !" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "WARNING:\tI think I deserve to have some extra bacon for free. I have been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "ERROR:\t\tThis is unacceptable ! I want to speak to the manager now." << std::endl;
}

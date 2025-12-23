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
	int	i;

	std::string states[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (i = 0; i < 4; i++)
		if (level == states[i])
			break ;
	switch (i)
	{
	case 0:
		debug();
	case 1:
		info();
	case 2:
		warning();
	case 3:
		error();
		break ;
	default:
		std::cout << "Unknown level:\t" << level << std::endl;
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

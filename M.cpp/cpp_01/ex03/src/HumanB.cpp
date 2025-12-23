/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:50:06 by ilymegy           #+#    #+#             */
/*   Updated: 2024/03/11 13:50:09 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanB.hpp"

HumanB::HumanB(std::string name):_name(name)
{
	std::cout << this->_name << " is ready to fight" << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << this->_name << " just died, bye" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
	if (!this->_weapon)
		std::cout << this->_name << " couldn't equip with a weapon." << std::endl;
	else
		std::cout << this->_name << " grabbed a " << this->_weapon->getType() << " to fight with" << std::endl;
}

void HumanB::attack(void)
{
	if (this->_weapon != NULL)
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " attacks" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:50:17 by ilymegy           #+#    #+#             */
/*   Updated: 2024/03/11 13:50:19 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Weapon.hpp"

Weapon::Weapon(const std::string &weapon)
{
	this->setType(weapon);
}

Weapon::~Weapon(void)
{
	std::cout << this->getType() << " has been destroyed" << std::endl;
}

std::string Weapon::getType(void) const
{
	return (_type);
}

void Weapon::setType(const std::string &weapon)
{
	_type = weapon;
}

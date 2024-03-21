/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:36:52 by ilymegy           #+#    #+#             */
/*   Updated: 2024/03/21 15:36:54 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
	: _health(10), _energy(10), _attackDamage(0)
{
	this->_name = name;
	std::cout << "ClapTrap " << this->_name << " appeared." << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &copy)
{
	*this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &assign)
{
	if (this != &assign)
		this->_name = assign._name;
	return (*this);
}

void ClapTrap::attack(const std::string &target){
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage !" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << " just died." << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:10:43 by ilymegy           #+#    #+#             */
/*   Updated: 2024/03/25 18:10:45 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): _name(name), _health(10), _energy(10), _attackDamage(0)
{
	std::cout << YELLOW << "ClapTrap " << this->_name << " appeared." << RESET << std::endl;
	return ;
}
ClapTrap::~ClapTrap()
{
	std::cout << YELLOW << "ClapTrap " << this->_name << " disappeared." << RESET << std::endl;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const &copy)
{
	*this = copy;
	std::cout << "ClapTrap copy constructor called" << std::endl;
	return ;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &assign)
{
	std::cout << "ClapTrap Assignation operator called" << std::endl;
	if (this != &assign)
		this->_name = assign._name;
	return (*this);
}

void ClapTrap::attack(const std::string &target)
{
	if (!_energy || !_health)
	{
		if (!_energy )
			std::cout << RED << "ClapTrap " << _name << " is out of energy!\n" << RESET << std::endl;
		if (!_health )
			std::cout << RED << "ClapTrap " << _name << " health is too low!\n" << RESET << std::endl;
		return ;
	}
	std::cout << CYAN << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage !\n" << RESET << std::endl;
	_energy -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << BLUE << "ClapTrap " << _name << " is being attacked and takes " << amount << " damage!" << std::endl;
	if (!_health)
	{
		std::cout << "but hopefully is" << MAGENTA << " already dead.\n" << RESET << std::endl;
		return;
	}
	if (amount >= _health)
	{
		std::cout << "and has been" << RED << " beaten to death.\n" << RESET << std::endl;
		_health = 0;
		return;
	}
	else
		std::cout << std::endl;
	_health -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!_energy)
	{
		std::cout << RED << "ClapTrap " << _name << " is out of energy!\n" << RESET << std::endl;
		return ;
	}
	std::cout << GREEN << "ClapTrap " << _name << " heals itself for " << amount << " hit points!\n" << RESET << std::endl;
	_health += amount;
	_energy -= 1;
}

void ClapTrap::showStats(void)
{
	std::cout << "-----------------------\n\tStats\n-----------------------" << std::endl;
	std::cout << "name \t:\t" << _name << std::endl;
	std::cout << "health \t:\t" << _health << std::endl;
	std::cout << "energy \t:\t" << _energy << std::endl;
	std::cout << "attack \t:\t" << _attackDamage << std::endl;
	std::cout << std::endl;
}

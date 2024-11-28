/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 18:29:52 by ilymegy           #+#    #+#             */
/*   Updated: 2024/03/28 18:29:54 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

ClapTrap::ClapTrap(void): _name("no_name"), _health(10), _energy(10), _attackDamage(0)
{
	std::cout << YELLOW << "ClapTrap " << this->_name << " appeared." << RESET << std::endl;
	return ;
}

ClapTrap::ClapTrap(const std::string name): _name(name), _health(10), _energy(10), _attackDamage(0)
{
	std::cout << YELLOW << "ClapTrap " << this->_name << " appeared." << RESET << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &copy)
{
	*this = copy;
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &assign)
{
	std::cout << "ClapTrap Assignation operator called" << std::endl;
	if (this != &assign)
	{
		this->_name = assign._name;
		this->_attackDamage = assign._attackDamage;
		this->_health = assign._health;
		this->_energy = assign._energy;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << YELLOW << "ClapTrap " << this->_name << " disappeared." << RESET << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (!_health || !_energy)
	{
		if (!_health)
			std::cout << RED << "ClapTrap " << _name << " health is too low!\n" << RESET << std::endl;
		if (!_energy)
			std::cout << RED << "ClapTrap " << _name << " is out of energy!\n" << RESET << std::endl;
		return ;
	}
	std::cout << CYAN << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage !\n" << RESET << std::endl;
	_energy -= 1;
	return;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!_energy)
	{
		std::cout << RED << "ClapTrap " << _name << " is out of energy!" << RESET << std::endl;
		return ;
	}
	if (_health == UINT_MAX)
	{
		std::cout << RED << "ClapTrap " << _name << " is already full of energy!" << RESET << std::endl;
		return ;
	}
	_energy -= 1;
	if (_health > UINT_MAX - amount)
	{
		std::cout << GREEN << "ClapTrap " << _name << " heals itself for " << amount - _health << " hit points!" << RESET << std::endl;
		_health = UINT_MAX;
		return;
	}
	std::cout << GREEN << "ClapTrap " << _name << " heals itself for " << amount << " hit points!" << RESET << std::endl;
	_health += amount;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << BLUE << "ClapTrap " << _name << " is being attacked and takes " << amount << " damage!" << std::endl;
	if (!_health)
		std::cout << "but hopefully is" << MAGENTA << " already dead.\n" << RESET << std::endl;
	else if (amount >= _health)
	{
		std::cout << "and has been" << RED << " beaten to death.\n" << RESET << std::endl;
		_health = 0;
	}
	else
	{
		std::cout << std::endl;
		_health -= amount;
	}
}

void ClapTrap::showStats()
{
	std::cout << "-----------------------\n\tStats\n-----------------------" << std::endl;
	std::cout << "name \t:\t" << _name << std::endl;
	std::cout << "health \t:\t" << _health << std::endl;
	std::cout << "energy \t:\t" << _energy << std::endl;
	std::cout << "attack \t:\t" << _attackDamage << std::endl;
	std::cout << std::endl;
}

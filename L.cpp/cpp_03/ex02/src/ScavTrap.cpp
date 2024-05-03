/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 18:30:05 by ilymegy           #+#    #+#             */
/*   Updated: 2024/03/28 18:30:07 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap("no_name"), _gate(false)
{
	std::cout << YELLOW << "ScavTrap " << this->_name << " appeared." << RESET << std::endl;
	this->showStats();
	std::cout << YELLOW << "||                   ||" << std::endl;
	std::cout << "\\/                   \\/" << RESET << std::endl;
	this->_attackDamage = 20;
	this->_health = 100;
	this->_energy = 50;
	this->showStats();
	std::cout << "\n\n" << std::endl;
	return ;
}

ScavTrap::ScavTrap(const std::string name): ClapTrap(name), _gate(false)
{
	this->_health = 100;
	this->_energy = 50;
	this->_attackDamage = 20;
	std::cout << YELLOW << "ScavTrap " << this->_name << " appeared." << RESET << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &copy): ClapTrap(copy)
{
	std::cout << YELLOW << "ScavTrap copy constructor called" << RESET << std::endl;
	this->_gate = copy._gate;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &assign)
{
	std::cout << YELLOW << "ScavTrap Assignation operator called" << RESET << std::endl;
	if (this != &assign)
	{
		this->_name = assign._name;
		this->_health = assign._health;
		this->_energy = assign._energy;
		this->_attackDamage = assign._attackDamage;
		this->_gate = assign._gate;
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << YELLOW << "ScavTrap " << this->_name << " disappeared." << RESET << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (!_health || !_energy)
	{
		if (!_health)
			std::cout << RED << "ScavTrap " << _name << " is out of energy!\n" << RESET << std::endl;
		if (!_energy)
			std::cout << RED << "ScavTrap " << _name << " health is too low!\n" << RESET << std::endl;
		return;
	}
	std::cout << CYAN << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage !\n" << RESET << std::endl;
	_energy -= 1;
}

void ScavTrap::guardGate()
{
	if (!this->_gate)
	{
		this->_gate = true;
		std::cout << GREEN << "ScavTrap " << this->_name << " is now keeping the gate.\n" << RESET << std::endl;
		return;
	}
	std::cout << GREEN << "ScavTrap " << this->_name << " is already keeping the gate.\n" << RESET << std::endl;
}

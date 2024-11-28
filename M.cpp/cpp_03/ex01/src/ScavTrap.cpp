/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:11:00 by ilymegy           #+#    #+#             */
/*   Updated: 2024/03/25 18:11:02 by ilymegy          ###   ########.fr       */
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

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), _gate(false)
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

ScavTrap::ScavTrap(ScavTrap const &copy) : ClapTrap(copy)
{
	this->_gate = copy._gate;
	std::cout << YELLOW << "ScavTrap copy constructor called" << RESET << std::endl;
	return ;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &assign)
{
	std::cout << YELLOW << "ScavTrap Assignation operator called" << RESET << std::endl;
	if (this != &assign)
	{
		this->_gate = assign._gate;
		this->_health = assign._health;
		this->_energy = assign._energy;
		this->_attackDamage = assign._attackDamage;
		this->_name = assign._name;
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << YELLOW << "ScavTrap " << this->_name << " disappeared." << RESET << std::endl;
	return ;
}

void ScavTrap::attack(const std::string &target)
{
	if (!_energy || !_health)
	{
		if (!_energy )
			std::cout << RED << "ScavTrap " << _name << " is out of energy!\n" << RESET << std::endl;
		if (!_health )
			std::cout << RED << "ScavTrap " << _name << " health is too low!\n" << RESET << std::endl;
		return ;
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

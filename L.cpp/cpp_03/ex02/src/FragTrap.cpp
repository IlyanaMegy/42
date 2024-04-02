/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 18:30:17 by ilymegy           #+#    #+#             */
/*   Updated: 2024/03/28 18:30:18 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FragTrap.hpp"

FragTrap::FragTrap(const std::string name): ClapTrap(name)
{
	std::cout << YELLOW << "FragTrap " << this->_name << " appeared." << RESET << std::endl;
	this->showStats();
	std::cout << YELLOW << "||                   ||" << std::endl;
	std::cout << "\\/                   \\/" << RESET << std::endl;
	this->_health = 100;
	this->_energy = 100;
	this->_attackDamage = 30;
	this->showStats();
	std::cout << "\n\n" << std::endl;
}

FragTrap::FragTrap(FragTrap const &copy): ClapTrap(copy)
{
	std::cout << YELLOW << "FragTrap copy constructor called" << RESET << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &assign)
{
	std::cout << YELLOW << "FragTrap Assignation operator called" << RESET << std::endl;
	if (this != &assign)
	{
		this->_name = assign._name;
		this->_health = assign._health;
		this->_energy = assign._energy;
		this->_attackDamage = assign._attackDamage;
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << YELLOW << "FragTrap " << this->_name << " disappeared." << RESET << std::endl;
}

void FragTrap::highFivesGuys()
{
	if (!this->_energy)
		std::cout << RED << "FragTrap " << _name << " is out of energy!\n" << RESET << std::endl;
	else{
		this->_energy -=1;
		std::cout << GREEN << "FragTrap " << _name << " high fives his friends <3." << RESET << std::endl;
	}
}

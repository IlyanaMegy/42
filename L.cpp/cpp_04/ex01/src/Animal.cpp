/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:48:09 by ilymegy           #+#    #+#             */
/*   Updated: 2024/04/09 14:48:10 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"

Animal::Animal(void): _type("default")
{
	std::cout << YELLOW << this->getType() << " Animal has been created." << RESET << std::endl;
}

Animal::Animal(Animal const &copy)
{
	std::cout << YELLOW << "Animal Copy constructor has been called." << RESET << std::endl;
	*this = copy;
}

Animal &Animal::operator=(Animal const &assign)
{
	std::cout << YELLOW << "Animal Assignation operator has been called." << RESET << std::endl;
	if (this != &assign)
		this->_type = assign._type;
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << YELLOW << this->getType() << " Animal has been killed." << RESET << std::endl;
}

std::string Animal::getType(void)const
{
	return (this->_type);
}

void Animal::makeSound(void)const
{
	std::cout << YELLOW << this->getType() << " Animal doesn't make any sound." << RESET << std::endl;
}

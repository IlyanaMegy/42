/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:42:07 by ilymegy           #+#    #+#             */
/*   Updated: 2024/04/04 13:42:08 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"

Animal::Animal(): _type("default")
{
	std::cout << YELLOW << "You've created an animal." << RESET << std::endl;
}

Animal::Animal(Animal const &copy)
{
	*this = copy;
	std::cout << YELLOW << "Animal Copy constructor has been called." << RESET << std::endl;
}

Animal &Animal::operator=(Animal const &assign)
{
	std::cout << YELLOW << "Animal Assignation operator has been called." << RESET << std::endl;
	if (this != &assign)
		this->_type = assign._type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << YELLOW << "An animal has been killed." << RESET << std::endl;
}

std::string Animal::getType() const
{
	return (this->_type);
}

void Animal::makeSound() const
{
	std::cout << YELLOW << "This animal doesn't make any sound." << RESET << std::endl;
}
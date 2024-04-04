/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:41:59 by ilymegy           #+#    #+#             */
/*   Updated: 2024/04/04 13:42:00 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

Cat::Cat() : Animal()
{
	this->_type = "Kitty";
	std::cout << ORANGE "And it's a " << this->_type << "!" << RESET << std::endl;
}

Cat::Cat(Cat const &copy) : Animal()
{
	*this = copy;
	std::cout << ORANGE << "Cat Copy constructor has been called." << RESET << std::endl;
}

Cat &Cat::operator=(Cat const &assign)
{
	std::cout << ORANGE << "Cat Assignation operator has been called." << RESET << std::endl;
	if (this != &assign)
		this->_type = assign._type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << ORANGE << this->getType() << " has been killed." << RESET << std::endl;
}

void Cat::makeSound()const
{
	std::cout << ORANGE << this->getType() << " says: Nyaaa :3" << RESET << std::endl;
}

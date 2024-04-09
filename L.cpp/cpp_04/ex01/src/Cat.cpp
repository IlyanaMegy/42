/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:46:44 by ilymegy           #+#    #+#             */
/*   Updated: 2024/04/09 14:46:46 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

Cat::Cat(void): Animal()
{
	this->_type = "kitty";
	this->_brain = new Brain();
	if (this->_brain == NULL)
	{
		perror("Cat Brain allocation failed");
		std::cerr << "Exiting the process now." << std::endl;
		exit(1);
	}
	std::cout << ORANGE << this->_type << " has a brain." << RESET << std::endl;
}

Cat::Cat(Cat const &copy): Animal()
{
	std::cout << ORANGE << "Cat Copy constructor has been called" << RESET << std::endl;
	*this = copy;
}

Cat &Cat::operator=(Cat const &assign)
{
	if (this != &assign)
	{
		this->_type = assign._type;
		this->_brain = new Brain(*assign._brain);
		if (this->_brain == NULL)
		{
			perror("Cat Brain allocation failed");
			std::cerr << "Exiting the process now." << std::endl;
			exit(1);
		}
	}
	return (*this);
}

Cat::~Cat( =void)
{
    std::cout << ORANGE << this->_type << " has been killed." << RESET << std::endl;
    delete  this->_brain;
}

void Cat::makeSound(void) const
{
	std::cout << ORANGE << this->getType() << " says: Nyaaa :3" << RESET << std::endl;
}
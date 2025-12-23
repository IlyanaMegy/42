/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:41:52 by ilymegy           #+#    #+#             */
/*   Updated: 2024/04/04 13:41:54 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

Dog::Dog(void): Animal()
{
	this->_type = "Doggy";
	std::cout << RED << "And it's a " << this->_type << "!" << RESET << std::endl;
}

Dog::Dog(Dog const &copy): Animal()
{
	std::cout << RED << "Dog Copy constructor has been called." << RESET << std::endl;
	*this = copy;
}

Dog &Dog::operator=(Dog const &assign)
{
	std::cout << RED << "Dog Assignation copy has been called." << RESET << std::endl;
	if(this != &assign)
		this->_type = assign._type;
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << RED << this->getType() << " has been killed." << RESET << std::endl;
}

void Dog::makeSound(void)const
{
	std::cout << RED << this->getType() << " says : Awoooo :O" << RESET << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:21:31 by ilymegy           #+#    #+#             */
/*   Updated: 2024/04/09 14:21:32 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal()
{
	this->_type = "broken cat";
	std::cout << BLUE << "And it's a " << this->_type << "!" << RESET << std::endl;
}

WrongCat::WrongCat(WrongCat const &copy): WrongAnimal()
{
	*this = copy;
	std::cout << BLUE << "Broken Cat Copy constructor has been called." << RESET << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &assign)
{
	std::cout << BLUE << "Broken Cat Assignation copy has been called." << RESET << std::endl;
	if(this != &assign)
		this->_type = assign._type;
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << BLUE << this->getType() << " has been killed." << RESET << std::endl;
}

void WrongCat::makeSound(void)const
{
	std::cout << BLUE << this->getType() << " says : Nyaaanadlaagdwhj :S" << RESET << std::endl;
}

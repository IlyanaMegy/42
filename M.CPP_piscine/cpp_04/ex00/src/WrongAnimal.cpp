/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:21:24 by ilymegy           #+#    #+#             */
/*   Updated: 2024/04/09 14:21:26 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): _type("broken animal")
{
	std::cout << MAGENTA << "You've created a broken animal." << RESET << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &copy)
{
	std::cout << MAGENTA << "Broken Animal Copy constructor has been called." << RESET << std::endl;
	*this = copy;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &assign)
{
	std::cout << MAGENTA << "Broken Animal Assignation operator has been called." << RESET << std::endl;
	if (this != &assign)
		this->_type = assign._type;
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << MAGENTA << "A broken animal has been killed." << RESET << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return (this->_type);
}

void WrongAnimal::makeSound(void) const
{
	std::cout << MAGENTA << "This broken animal doesn't make any sound." << RESET << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:43:11 by ilymegy           #+#    #+#             */
/*   Updated: 2024/04/23 13:43:13 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal()
{
	this->_type = "broken kitty";
	this->_brain = new Brain();
	if (!this->_brain)
	{
		std::cerr << "Broken Cat Brain allocation failed. Exiting the process now." << std::endl;
		exit(1);
	}
	std::cout << PINK << this->_type << " has a brain." << RESET << std::endl;
}

WrongCat::WrongCat(WrongCat const &copy): WrongAnimal()
{
	std::cout << PINK << "Broken Cat Copy constructor has been called." << RESET << std::endl;
	*this = copy;
}

WrongCat &WrongCat::operator=(WrongCat const &assign)
{
	std::cout << PINK << "Broken Cat Assignation copy has been called." << RESET << std::endl;
	if (this != &assign)
	{
		this->_type = assign._type;
		this->_brain = new Brain();
		if (!this->_brain)
		{
			std::cerr << "Broken Cat Brain allocation failed. Exiting the process now." << std::endl;
			exit(1);
		}
	}
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << PINK << this->getType() << " has been killed." << RESET << std::endl;
	delete this->_brain;
}

void WrongCat::makeSound(void) const
{
	std::cout << PINK << this->getType() << " says : Nyaaanadlaagdwhj :S" << RESET << std::endl;
}

void WrongCat::addIdeas(std::string idea)
{
	for (int i = 0; i < 100; i++)
	{
		if (this->_brain->getIdea(i) == "")
		{
			this->_brain->setIdea(i, idea);
			return ;
		}
	}
	std::cout << RED << "/!\\" << PINK << "Brain of " << this->getType() << " is full!" << RESET << std::endl;	
}

void WrongCat::expressIdeas(void) const
{
	std::string idea;
	std::cout << PINK << this->getType() << "'s ideas:" << RESET << std::endl;
	for (int i = 0; i < 100; i++)
	{
		idea = this->_brain->getIdea(i);
		if (idea.empty())
			return ;
		std::cout << PINK << idea << RESET << std::endl;
	}
}

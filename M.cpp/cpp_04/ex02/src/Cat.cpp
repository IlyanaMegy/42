/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:41:46 by ilymegy           #+#    #+#             */
/*   Updated: 2024/04/23 13:41:51 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

Cat::Cat(void): AAnimal()
{
	this->_type = "kitty";
	this->_brain = new Brain();
	if (this->_brain == NULL)
	{
		std::cerr << "Cat Brain allocation failed. Exiting the process now." << std::endl;
		exit(1);
	}
	std::cout << ORANGE << this->_type << " has a brain." << RESET << std::endl;
}

Cat::Cat(Cat const &copy): AAnimal()
{
	std::cout << ORANGE << "Cat Copy constructor has been called" << RESET << std::endl;
	this->_type = copy._type;
	this->_brain = new Brain(*copy._brain);
	if (this->_brain == NULL)
	{
		std::cerr << "Cat Brain allocation failed. Exiting the process now." << std::endl;
		exit(1);
	}
}

Cat &Cat::operator=(Cat const &assign)
{
	std::cout << ORANGE << "Cat Assignation copy constructor has been called" << RESET << std::endl;
	if (this != &assign)
	{
		if (this->_brain != NULL)
			delete this->_brain;
		this->_type = assign._type;
		this->_brain = new Brain(*assign._brain);
		if (this->_brain == NULL)
		{
			std::cerr << "Cat Brain allocation failed. Exiting the process now." << std::endl;
			exit(1);
		}
	}
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << ORANGE << this->_type << " has been killed." << RESET << std::endl;
	delete this->_brain;
}

void Cat::makeSound(void) const
{
	std::cout << ORANGE << this->getType() << " says: Nyaaa :3" << RESET << std::endl;
}

void Cat::addIdeas(std::string idea)
{
	for (int i = 0; i < 100; i++)
	{
		if (this->_brain->getIdea(i) == "")
		{
			this->_brain->setIdea(i, idea);
			return ;
		}
	}
	std::cout << RED << "/!\\" << ORANGE << "Brain of " << this->getType() << " is full!" << RESET << std::endl;
}

void Cat::expressIdeas() const
{
	std::string idea;
	std::cout << ORANGE << this->getType() << "'s ideas:" << RESET << std::endl;
	for (int i = 0; i < 100; i++)
	{
		idea = this->_brain->getIdea(i);
		if (idea.empty())
			return;
		std::cout << ORANGE << idea << RESET << std::endl;
	}	
}

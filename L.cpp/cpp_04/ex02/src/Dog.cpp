/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:42:00 by ilymegy           #+#    #+#             */
/*   Updated: 2024/04/23 13:42:07 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

Dog::Dog(void): AAnimal()
{
	this->_type = "doggy";
	this->_brain = new Brain();
	if (this->_brain == NULL)
	{
		std::cerr << "Dog Brain allocation failed. Exiting the process now." << std::endl;
		exit(1);
	}
	std::cout << CYAN << this->_type << " has a brain." << RESET << std::endl;
}

Dog::Dog(Dog const &copy): AAnimal()
{
	std::cout << CYAN << "Dog Copy constructor has been called" << RESET << std::endl;
	*this = copy;
}

Dog &Dog::operator=(Dog const &assign)
{
	std::cout << CYAN << "Dog Assignation copy constructor has been called" << RESET << std::endl;
	if (this != &assign)
	{
		this->_type = assign._type;
		this->_brain = new Brain();
		if (this->_brain == NULL)
		{
			std::cerr << "Dog Brain allocation failed. Exiting the process now." << std::endl;
			exit(1);
		}
	}
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << CYAN << this->_type << " has been killed." << RESET << std::endl;
	delete this->_brain;
}

void Dog::makeSound(void) const
{
	std::cout << CYAN << this->getType() << " says : Awoooo :O" << RESET << std::endl;
}

void Dog::addIdea(std::string idea)
{
	for (int i = 0; i < 100; i++)
	{
		if (this->_brain->getIdea(i) == "")
		{
			this->_brain->setIdea(i, idea);
			return ;
		}
	}
	std::cout << RED << "/!\\" << CYAN << "Brain of " << this->getType() << " is full!" << RESET << std::endl;
}

void Dog::expressIdeas(void) const
{
	std::string idea;
	std::cout << CYAN << this->getType() << "'s ideas:" << RESET << std::endl;
	for (int i = 0; i < 100; i++)
	{
		idea = this->_brain->getIdea(i);
		if (idea.empty())
			return ;
		std::cout << CYAN << idea << RESET << std::endl;
	}
}

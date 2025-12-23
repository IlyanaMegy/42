/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:46:51 by ilymegy           #+#    #+#             */
/*   Updated: 2024/04/09 14:46:52 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

Dog::Dog(void): Animal()
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

Dog::Dog(Dog const &copy): Animal()
{
	std::cout << CYAN << "Dog Copy constructor has been called" << RESET << std::endl;
	this->_type = copy._type;
	this->_brain = new Brain(*copy._brain);
	if (this->_brain == NULL)
	{
		std::cerr << "Cat Brain allocation failed. Exiting the process now." << std::endl;
		exit(1);
	}
}

Dog &Dog::operator=(Dog const &assign)
{
	std::cout << CYAN << "Dog Assignation copy constructor has been called" << RESET << std::endl;
	if (this != &assign)
	{
		if (this->_brain != NULL)
			delete this->_brain;
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

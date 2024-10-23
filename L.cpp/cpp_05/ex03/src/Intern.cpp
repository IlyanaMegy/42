/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 21:01:15 by ilymegy           #+#    #+#             */
/*   Updated: 2024/10/17 21:01:17 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern Default Constructor called" << std::endl;
}

Intern::Intern(Intern const &src)
{
	std::cout << "Intern Copy Constructor called" << std::endl;
	*this = src;
}

Intern &Intern::operator=(Intern const &src)
{
	std::cout << "Intern Assignation operator called" << std::endl;
	if (this != &src)
		return *this;
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern Deconstructor called" << std::endl;
}

static AForm *makePPForm(const std::string target)
{
	return (new PPForm(target));
}

static AForm *makeRRForm(const std::string target)
{
	return (new RRForm(target));
}

static AForm *makeSCForm(const std::string target)
{
	return (new SCForm(target));
}

AForm *Intern::makeForm(const std::string form, const std::string target)
{
	AForm *(*all_forms[])(const std::string target) = {&makePPForm, &makeRRForm, &makeSCForm};
	std::string forms[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

	for (int i = 0; i < 3; i++)
		if (form == forms[i])
			return (all_forms[i](target));
	std::cout << "\033[33mIntern can not create a form called " << form << "\033[0m" << std::endl;
	return (NULL);
}
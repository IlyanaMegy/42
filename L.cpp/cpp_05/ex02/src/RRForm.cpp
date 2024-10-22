/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RRForm.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:33:47 by ilymegy           #+#    #+#             */
/*   Updated: 2024/10/07 14:33:48 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RRForm.hpp"

RRForm::RRForm(): AForm("RobotomyRequestForm", 72, 45), _target("")
{
	std::cout << "Error: Target must be specified '" << _target << "' is not recognized." << std::endl;
	throw std::invalid_argument("Target must be specified");
}

RRForm::RRForm(std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	if (_target.empty())
	{
		std::cout << "Error: Target must be specified '" << _target << "' is not recognized." << std::endl;
		throw std::invalid_argument("Target must be specified");
	}
}

RRForm::RRForm(RRForm const &src): AForm(src), _target(src._target)
{
	if (_target.empty())
	{
		std::cout << "Error: Target must be specified '" << _target << "' is not recognized." << std::endl;
		throw std::invalid_argument("Target must be specified");
	}
}

RRForm::~RRForm()
{
	std::cout << RED << "RobotomyRequestForm Destructor called" << std::endl;
}

RRForm &RRForm::operator=(RRForm const &src)
{
	std::cout << "ShrubberyCreationForm Assignation operator called" << std::endl;
	if (this != &src)
		return *this;
	return *this;
}

void RRForm::executeAction() const
{
	if (rand() % 2)
		std::cout << "BRRRRRRRRRRRRRR\n" << this->getTarget() << " was robotomized" << std::endl;
	else
		std::cout << "Robotomy of " << this->getTarget() << "failed" << std::endl;
}

std::string RRForm::getTarget(void)const
{
	return (this->_target);
}

std::ostream &operator<<(std::ostream &o, RRForm *a)
{
	o << MAGENTA << "\n* Form " << a->getName() << "\n  sign grade : " << a->getSignGrade() <<
	"\n  execution grade : " << a->getExecGrade() << "\n  signed : " << a->getIsSigned() << RESET << std::endl;
	return (o);
}

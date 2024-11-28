/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:33:47 by ilymegy           #+#    #+#             */
/*   Updated: 2024/10/07 14:33:48 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"

static std::string verifTarget(std::string t)
{
	if (t.empty())
	{
		std::cout << "Error: Target must be specified '" << t << "' is not recognized." << std::endl;
        throw std::invalid_argument("Target must be specified");
	}
	return (t);
}

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), _target("")
{
	std::cout << "Error: Target must be specified '" << _target << "' is not recognized." << std::endl;
	throw std::invalid_argument("Target must be specified");
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), _target(verifTarget(target))
{
	std::cout << ORANGE << "RobotomyRequestForm Constructor called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src): AForm(src), _target(verifTarget(src.getTarget()))
{
	std::cout << ORANGE << "RobotomyRequestForm Copy Constructor called to copy " << src.getName() <<
	" into " << this->getName() << RESET << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << RED << "RobotomyRequestForm Destructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &src)
{
	std::cout << "RobotomyRequestForm Assignation operator called" << std::endl;
	if (this != &src)
		this->_target = verifTarget(src._target);
	return *this;
}

void RobotomyRequestForm::executeAction() const
{
	if (rand() % 2)
		std::cout << "BRRRRRRRRRRRRRR\n" << this->getTarget() << " was robotomized" << std::endl;
	else
		std::cout << "Robotomy of " << this->getTarget() << "failed" << std::endl;
}

std::string RobotomyRequestForm::getTarget(void)const
{
	return (this->_target);
}

std::ostream &operator<<(std::ostream &o, RobotomyRequestForm *a)
{
	o << MAGENTA << "\n* Form " << a->getName() << "\n  sign grade : " << a->getSignGrade() <<
	"\n  execution grade : " << a->getExecGrade() << "\n  signed : " << a->getIsSigned() << RESET << std::endl;
	return (o);
}

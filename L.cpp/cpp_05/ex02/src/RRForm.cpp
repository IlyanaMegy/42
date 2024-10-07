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

RRForm::RRForm(void): AForm("RobotomyRequestForm", 72, 45), _target("default")
{
	std::cout << "RobotomyRequestForm Default Constructor called" << std::endl;
}

RRForm::RRForm(std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm for target " << CYAN << this->getTarget() << RESET << " called" << std::endl;
}

RRForm::RRForm(RRForm const &copy): AForm("RobotomyRequestForm", 72, 45), _target(copy.getTarget())
{
	std::cout << ORANGE << "RobotomyRequestForm Copy Constructor called to copy " << copy.getName() <<
	" into " << this->getName() << RESET << std::endl;
	*this = copy;
}

RRForm::~RRForm(void)
{
	std::cout << RED << "RobotomyRequestForm Destructor called" << std::endl;
}

RRForm &RRForm::operator=(RRForm const &assign)
{
	std::cout << "RobotomyRequestForm Assignation operator called" << std::endl;
	if (this != &assign)
		return *this;
	return *this;
}

static int bot_fail = 0;

void RRForm::execute(Bureaucrat const &executor) const
{
	if ((int)executor.getGrade() > this->getExecGrade())
		throw (Bureaucrat::GradeTooLowException());
	else if (!this->getSignedBool())
		throw (AForm::FormNotSignedException());
	else if (bot_fail++ % 2)
		std::cout << "BRRRRRRRRRRRRRR\n" << this->getTarget() << " was robotomized" << std::endl;
	else
		std::cout << "Robotomy failed" << std::endl;
}

std::string RRForm::getTarget(void)const
{
	return (this->_target);
}

std::ostream &operator<<(std::ostream &o, Form *a)
{
	o << MAGENTA << "\n* Form --> " << a->getName() << "\nsign grade : " << a->getSignGrade() <<
	"\nexecution grade : " << a->getExecGrade() << "\nsigned : " << a->getSigned() << RESET << std::endl;
	return (o);
}

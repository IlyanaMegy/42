/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RRForm.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 21:00:38 by ilymegy           #+#    #+#             */
/*   Updated: 2024/10/17 21:00:40 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RRForm.hpp"

std::string verifTarget(std::string t)
{
	if (t.empty())
	{
		std::cout << "Error: Target must be specified '" << _target << "' is not recognized." << std::endl;
		throw std::invalid_argument("Target must be specified");
	}
	return (t);
}

RRForm::RRForm() : AForm("RobotomyRequestForm", 72, 45), _target(verifTarget(""))
{}

RRForm::RRForm(RRForm const &src) : AForm("RobotomyRequestForm", 72, 45), _target(verifTarget(src.getTarget()))
{}

RRForm::RRForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(verifTarget(target))
{}

RRForm &RRForm::operator=(RRForm const &src)
{
	if (this != &src)
		this->_target = verifTarget(src.getTarget());
	return *this;
}

RRForm::~RRForm()
{}

std::string RRForm::getTarget() const
{
	return (this->_target);
}

void RRForm::executeAction() const
{
	if (rand() % 2)
		std::cout << "BRRRRRRRRRRRRRR\n" << this->getTarget() << " was robotomized" << std::endl;
	else
		std::cout << "Robotomy of " << this->getTarget() << "failed" << std::endl;
}

std::ostream &operator<<(std::ostream &o, RRForm *a)
{
	o << MAGENTA << "\n* Form " << a->getName() << "\n  sign grade : " << a->getSignGrade() <<
	"\n  execution grade : " << a->getExecGrade() << "\n  signed : " << a->getIsSigned() << RESET << std::endl;
	return (o);
}

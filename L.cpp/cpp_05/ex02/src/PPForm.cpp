/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PPForm.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:33:18 by ilymegy           #+#    #+#             */
/*   Updated: 2024/10/07 14:33:19 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PPForm.hpp"

PPForm::PPForm(void): AForm("PresidentialPardonForm", 25, 5), _target("default")
{
	std::cout << "PresidentialPardonForm Default Constructor called" << std::endl;
}

PPForm::PPForm(std::string target): AForm("PresidentialPardonForm", 25, 5), _target("default")
{
	std::cout << "PresidentialPardonForm Constructor for target " << CYAN << this->getTarget() << RESET << " called" << std::endl;
}

PPForm::PPForm(PPForm const &copy): AForm("PresidentialPardonForm", 25, 5), _target(copy.getTarget())
{
	std::cout << ORANGE << "PresidentialPardonForm Copy Constructor called to copy " << copy.getName() <<
	" into " << this->getName() << RESET << std::endl;
	*this = copy;
}

PPForm::~PPForm(void)
{
	std::cout << RED << "PresidentialPardonForm Destructor called" << std::endl;
}

PPForm &PPForm::operator=(PPForm const &assign)
{
	std::cout << "PresidentialPardonForm Assignation operator called" << std::endl;
	if (this != &assign)
		return *this;
	return *this;
}

void PPForm::execute(Bureaucrat const &executor)const
{
	if ((int)executor.getGrade() > this->getExecGrade())
		throw (Bureaucrat::GradeTooLowException());
	else if (!this->getSignedBool())
		throw (AForm::FormNotSignedException());
	else
		std::cout << BLUE << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << RESET << std::endl;
}

std::string PPForm::getTarget(void)const
{
	return (this->_target);
}

std::ostream &operator<<(std::ostream &o, Form *a)
{
	o << MAGENTA << "\n* Form --> " << a->getName() << "\nsign grade : " << a->getSignGrade() <<
	"\nexecution grade : " << a->getExecGrade() << "\nsigned : " << a->getSigned() << RESET << std::endl;
	return (o);
}

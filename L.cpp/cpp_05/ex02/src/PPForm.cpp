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

PPForm::PPForm(std::string target): AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	if (this->_target.empty())
    {
        std::cout << "Error: Target must be specified '" << this->_target << "' is not recognized." << std::endl;
        throw std::invalid_argument("Target must be specified");
    }
	std::cout << "PresidentialPardonForm Constructor for target " << CYAN << this->getTarget() << RESET << " called" << std::endl;
}

PPForm::PPForm(PPForm const &src): AForm("PresidentialPardonForm", 25, 5), _target(src.getTarget())
{
	if (this->_target.empty())
    {
        std::cout << "Error: Target must be specified '" << this->_target << "' is not recognized." << std::endl;
        throw std::invalid_argument("Target must be specified");
    }
	std::cout << ORANGE << "PresidentialPardonForm Copy Constructor called to copy " << src.getName() <<
	" into " << this->getName() << RESET << std::endl;
}

PPForm::~PPForm()
{
	std::cout << RED << "PresidentialPardonForm Destructor " << this->getName() << " called" << std::endl;
}

PPForm &PPForm::operator=(PPForm const &src)
{
	std::cout << "PresidentialPardonForm assignation operator called" << std::endl;
	if (this != &src)
	{
        AForm::operator = (src);
		if (src._target.empty())
		{
			std::cout << "Error: Target must be specified '" << this->_target << "' is not recognized." << std::endl;
			throw std::invalid_argument("Target must be specified");
		}
        this->_target = src._target;
    }
	return *this;
}

void PPForm::execute(Bureaucrat const &executor)const
{
	if (executor.getGrade() > this->getExecGrade())
		throw (Bureaucrat::GradeTooLowException());
	else if (!this->getIsSignedBool())
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
	o << MAGENTA << "\n* Form " << a->getName() << "\n  sign grade : " << a->getSignGrade() <<
	"\n  execution grade : " << a->getExecGrade() << "\n  signed : " << a->getSigned() << RESET << std::endl;
	return (o);
}

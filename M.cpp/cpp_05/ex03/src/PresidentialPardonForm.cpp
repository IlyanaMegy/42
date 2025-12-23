/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:33:18 by ilymegy           #+#    #+#             */
/*   Updated: 2024/10/07 14:33:19 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PresidentialPardonForm.hpp"

static std::string verifTarget(std::string t)
{
	if (t.empty())
	{
		std::cout << "Error: Target must be specified '" << t << "' is not recognized." << std::endl;
        throw std::invalid_argument("Target must be specified");
	}
	return (t);
}

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), _target("default")
{
	std::cout << "PresidentialPardonForm Default Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	if (this->_target.empty())
    {
        std::cout << "Error: Target must be specified '" << this->_target << "' is not recognized." << std::endl;
        throw std::invalid_argument("Target must be specified");
    }
	std::cout << "PresidentialPardonForm Constructor for target " << CYAN << this->getTarget() << RESET << " called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src): AForm("PresidentialPardonForm", 25, 5), _target(src.getTarget())
{
	if (this->_target.empty())
    {
        std::cout << "Error: Target must be specified '" << this->_target << "' is not recognized." << std::endl;
        throw std::invalid_argument("Target must be specified");
    }
	std::cout << ORANGE << "PresidentialPardonForm Copy Constructor called to copy " << src.getName() <<
	" into " << this->getName() << RESET << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << RED << "PresidentialPardonForm Destructor " << this->getName() << " called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &src)
{
	std::cout << "PresidentialPardonForm Assignation operator called" << std::endl;
	if (this != &src)
		this->_target = verifTarget(src._target);
	return *this;
}

void PresidentialPardonForm::executeAction() const
{
	std::cout << BLUE << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << RESET << std::endl;
}

std::string PresidentialPardonForm::getTarget()const
{
	return (this->_target);
}

std::ostream &operator<<(std::ostream &o, PresidentialPardonForm *a)
{
	o << MAGENTA << "\n* Form " << a->getName() << "\n  sign grade : " << a->getSignGrade() <<
	"\n  execution grade : " << a->getExecGrade() << "\n  signed : " << a->getIsSigned() << RESET << std::endl;
	return (o);
}

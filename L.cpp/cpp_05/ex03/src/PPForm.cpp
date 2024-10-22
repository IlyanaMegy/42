/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PPForm.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 21:00:45 by ilymegy           #+#    #+#             */
/*   Updated: 2024/10/17 21:00:47 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PPForm.hpp"

std::string verifTarget(std::string t)
{
	if (t.empty())
	{
		std::cout << "Error: Target must be specified '" << this->_target << "' is not recognized." << std::endl;
        throw std::invalid_argument("Target must be specified");
	}
	return (t);
}

PPForm::PPForm() : AForm("PresidentialPardonForm", 25, 5), _target("defaultT")
{}

PPForm::PPForm(PPForm const &src) : AForm("PresidentialPardonForm", 25, 5), _target(verifTarget(src.getTarget()))
{}

PPForm::PPForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(verifTarget(target))
{}

PPForm &PPForm::operator=(PPForm const &src)
{
	if (this != &src)
		this->_target = verifTarget(src._target);
	return *this;
}

PPForm::~PPForm()
{}

void PPForm::executeAction() const
{
	std::cout << BLUE << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << RESET << std::endl;
}

std::string PPForm::getTarget() const
{
	return (this->_target);
}

std::ostream &operator<<(std::ostream &o, PPForm *a)
{
	o << MAGENTA << "\n* Form " << a->getName() << "\n  sign grade : " << a->getSignGrade() <<
	"\n  execution grade : " << a->getExecGrade() << "\n  signed : " << a->getIsSigned() << RESET << std::endl;
	return (o);
}

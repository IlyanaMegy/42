/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SCForm.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:33:59 by ilymegy           #+#    #+#             */
/*   Updated: 2024/10/07 14:34:03 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/SCForm.hpp"

SCForm::SCForm(void): AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
	std::cout << "ShrubberyCreationForm Default Constructor called" << std::endl;
}

SCForm::SCForm(std::string target): AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm for target " << CYAN << this->getTarget() << RESET << " called" << std::endl;
}

SCForm::SCForm(SCForm const &copy): AForm("ShrubberyCreationForm", 145, 137), _target(copy.getTarget())
{
	std::cout << ORANGE << "ShrubberyCreationForm Copy Constructor called to copy " << copy.getName() <<
	" into " << this->getName() << RESET << std::endl;
	*this = copy;
}

SCForm::~SCForm(void)
{
	std::cout << RED << "RobotomyRequestForm Destructor called" << std::endl;
}

SCForm &SCForm::operator=(SCForm const &assign)
{
	std::cout << "ShrubberyCreationForm Assignation operator called" << std::endl;
	if (this != &src)
		return *this;
	return *this;
}

void SCForm::execute(Bureaucrat const &executor)const
{
	if ((int)executor.getGrade() > this->getExecGrade())
		throw (Bureaucrat::GradeTooLowException());
	else if (this->getIsSignedBool() == false)
		throw (AForm::FormNotSignedException());
	else
	{
		std::ofstream outfile (this->getTarget().append("_shrubbery").c_str());
		for (int i = 0; i < 5; i++)
		{
			outfile <<
			"         v" << std::endl <<
			"        >X<" << std::endl <<
			"         A" << std::endl <<
			"        d$b" << std::endl <<
			"      .d\\$$b." << std::endl <<
			"    .d$i$$\\$$b." << std::endl <<
			"       d$$@b" << std::endl <<
			"      d\\$$$ib" << std::endl <<
			"    .d$$$\\$$$b" << std::endl <<
			"  .d$$@$$$$\\$$ib." << std::endl <<
			"      d$$i$$b" << std::endl <<
			"     d\\$$$$@$b" << std::endl <<
			"  .d$@$$\\$$$$$@b." << std::endl <<
			".d$$$$i$$$\\$$$$$$b." << std::endl <<
			"        ###" << std::endl <<
			"        ###" << std::endl <<
			"        ###" << std::endl <<
		std::endl;
		}
		outfile.close();
	}
}

std::string	ShrubberyCreationForm::getTarget(void)const
{
	return (this->_target);
}

std::ostream &operator<<(std::ostream &o, Form *a)
{
	o << MAGENTA << "\n* Form --> " << a->getName() << "\nsign grade : " << a->getSignGrade() <<
	"\nexecution grade : " << a->getExecGrade() << "\nsigned : " << a->getSigned() << RESET << std::endl;
	return (o);
}

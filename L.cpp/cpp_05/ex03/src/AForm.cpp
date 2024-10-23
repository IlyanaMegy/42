/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 21:01:00 by ilymegy           #+#    #+#             */
/*   Updated: 2024/10/17 21:01:01 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"

AForm::AForm() : _name("defaultF"), _isSigned(false), _sign_grade(150), _exec_grade(150)
{}

AForm::AForm(AForm const &src) : _name(src._name + "_copy"), _isSigned(src.getIsSignedBool()), _sign_grade(src.getSignGrade()), _exec_grade(src.getExecGrade())
{}

AForm::AForm(const std::string name) : _name(name), _isSigned(false), _sign_grade(150), _exec_grade(150)
{}

AForm::AForm(int sign_grade, int exec_grade) : _name("defaultF"), _isSigned(false), _sign_grade(setGrade(sign_grade)), _exec_grade(setGrade(exec_grade))
{}

AForm::AForm(const std::string name, int sign_grade, int exec_grade) : _name(name), _isSigned(false), _sign_grade(setGrade(sign_grade)), _exec_grade(setGrade(exec_grade))
{}

AForm &AForm::operator=(AForm const &src)
{
	if (this != &src)
		this->_isSigned = src._isSigned;
	return *this;
}

AForm::~AForm()
{}

void AForm::doSign(Bureaucrat &b)
{
	if (b.getGrade() > this->getSignGrade())
		throw (GradeTooLowException());
	if (!this->getIsSignedBool())
	{
		this->_isSigned = true;
		std::cout << BLACK << "\nForm " << this->_name << " has been signed by " << b.getName() << RESET << std::endl;
		return;
	}
	std::cout << RED << "\nForm " << this->getName() << " has already been signed" << RESET << std::endl;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!this->_isSigned)
		throw (FormNotSignedException());
	if (executor.getGrade() > this->_exec_grade)
		throw (GradeTooLowException());
	executeAction();
}

const std::string AForm::getName() const
{
	return (this->_name);
}

const std::string AForm::getIsSigned() const
{
	if (this->_isSigned)
		return (TRUE_EMOJI);
	return (FALSE_EMOJI);
}

bool AForm::getIsSignedBool() const
{
	return (this->_isSigned);
}

size_t AForm::getSignGrade() const
{
	return (this->_sign_grade);
}

size_t AForm::getExecGrade() const
{
	return  (this->_exec_grade);
}

size_t AForm::setGrade(size_t grade)
{
	if (grade > 150)
		throw (AForm::GradeTooLowException());
	else if (grade < 1)
		throw (AForm::GradeTooHighException());
	return (grade);
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low /!\\");
};

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high /!\\");
};

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("Form needs to be signed before executing");
};

std::ostream &operator<<(std::ostream &o, AForm *a)
{
	o << MAGENTA << "\n* Form " << a->getName() << "\n  sign grade : " << a->getSignGrade() <<
	"\n  execution grade : " << a->getExecGrade() << "\n  signed : " <<
	a->getIsSigned() << RESET << std::endl;
	return (o);
}

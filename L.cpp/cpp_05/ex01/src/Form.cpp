/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:46:42 by ilymegy           #+#    #+#             */
/*   Updated: 2024/09/17 16:46:43 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"

Form::Form(): _name("default"), _isSigned(false), _sign_grade(150), _exec_grade(150)
{}

Form::Form(Form const &src): _name(src.getName()), _isSigned(src.getIsSignedBool()), _sign_grade(src.getSignGrade()), _exec_grade(src.getExecGrade())
{}

Form::Form(int sign_grade, int exec_grade): _name("default"), _isSigned(false), _sign_grade(setGrade(sign_grade)), _exec_grade(setGrade(exec_grade))
{}

Form::Form(const std::string name): _name(name), _isSigned(false), _sign_grade(150), _exec_grade(150)
{}

Form::Form(const std::string name, int sign_grade, int exec_grade): _name(name), _isSigned(false), _sign_grade(setGrade(sign_grade)), _exec_grade(setGrade(exec_grade))
{}

Form &Form::operator=(const Form &src)
{
	if (this != &src)
		return *this;
	return *this;
}

Form::~Form()
{}

void Form::beSigned(Bureaucrat &human)
{
	if (human.getGrade() > this->getSignGrade())
		throw (Bureaucrat::GradeTooLowException());
	if (!this->getIsSignedBool())
	{
		this->_isSigned = true;
		std::cout << BLACK << "\nForm " << this->_name << " has been signed by " << human.getName() << RESET << std::endl;
		return;
	}
	std::cout << RED << "\nForm " << this->_name << " has already been signed by " << this->getName() << RESET << std::endl;
}

const std::string Form::getName() const
{
	return (this->_name);
}

const std::string Form::getIsSigned() const
{
	if (this->_isSigned)
		return (TRUE_EMOJI);
	return (FALSE_EMOJI);
}

bool Form::getIsSignedBool() const
{
	return (this->_isSigned);
}

size_t Form::getSignGrade() const
{
	return (this->_sign_grade);
}

size_t Form::getExecGrade() const
{
	return (this->_exec_grade);
}

size_t Form::setGrade(int grade)
{
	if (grade > 150)
		throw (Form::GradeTooLowException());
	else if (grade < 1)
		throw (Form::GradeTooHighException());
	else
		return grade;
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low /!\\");
};

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high /!\\");
};

std::ostream &operator<<(std::ostream &o, Form *a)
{
	o << MAGENTA << "\n* Form " << a->getName() << "\n  sign grade : " << a->getSignGrade() <<
	"\n  execution grade : " << a->getExecGrade() << "\n  signed : " <<
	a->getIsSigned() << RESET << std::endl;
	return (o);
}

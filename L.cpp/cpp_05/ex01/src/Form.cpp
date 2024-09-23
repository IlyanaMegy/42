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

void print_infos(const std::string name, const std::string n_color, int sign_g, const std::string s_color, int exec_g, const std::string e_color, const std::string sign_emoji)
{
	std::cout << n_color  << "--> " << name << RESET <<
	"\nsign grade : " << s_color << sign_g << RESET <<
	"\nexecution grade : " << e_color << exec_g << RESET <<
	"\nsigned : " << sign_emoji << std::endl;
}

Form::Form(void): _name("default"), _signed(false), _sign_grade(150), _exec_grade(150)
{
	std::cout << "\n* Form Default Constructor called for " << std::endl;
	print_infos(this->getName(), YELLOW, this->getSignGrade(), YELLOW, this->getExecGrade(), YELLOW, FALSE_EMOJI);
	
	// std::string signed_state = FALSE_EMOJI;

	// std::cout << "Form Default Constructor called for " << YELLOW << this->getName() << RESET <<
	// ":\nsign grade : " << YELLOW << this->getSignGrade() << RESET <<
	// "\nexecution grede : " << YELLOW << this->getExecGrade() << RESET <<
	// "\nsigned : " << FALSE_EMOJI << std::endl;
}

Form::Form(Form const &copy): _name(copy.getName() + "_copy"), _signed(false), _sign_grade(copy.getSignGrade()), _exec_grade(copy.getExecGrade())
{
	std::cout << ORANGE << "\n* Form Copy Constructor copied " << copy.getName() << 
	" into " << this->getName() << RESET << std::endl;
	*this = copy;
}

Form::Form(int sign_grade, int exec_grade): _name("default"), _signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	std::cout << "\n* Form Constructor called for " << std::endl;
	print_infos(this->getName(), YELLOW, this->getSignGrade(), BLUE, this->getExecGrade(), BLUE, FALSE_EMOJI);

	// << YELLOW << this->getName() << RESET <<
	// ":\nsign grade : " << BLUE << this->getSignGrade() << RESET <<
	// "\nexecution grede : " << BLUE << this->getExecGrade() << RESET <<
	// "\nsigned : " << this->getSignedBool() << std::endl;
	
	const int i = this->getSignGrade();
	const int j = this->getExecGrade();
	if (i > 150 || j > 150)
		throw(Form::GradeTooLowException());
	else if (i < 1 || j < 1)
		throw(Form::GradeTooHighException());
}

Form::Form(const std::string name): _name(name), _signed(false), _sign_grade(150), _exec_grade(150)
{
	std::cout << "\n* Form Constructor called for " << std::endl;
	print_infos(this->getName(), BLUE, this->getSignGrade(), YELLOW, this->getExecGrade(), YELLOW, FALSE_EMOJI);
	
	// std::cout << "Form Constructor called for " << BLUE << this->getName() << RESET << 
	// ":\nsign grade : " << YELLOW << this->getSignGrade() << RESET <<
	// "\nexecution grade : " << YELLOW << this->getExecGrade() << RESET <<
	// "\nsigned : " << this->getSignedBool() << std::endl;
}

Form::Form(const std::string name, int sign_grade, int exec_grade): _name(name), _signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	std::cout << "\n* Form Constructor called for " << std::endl;
	print_infos(this->getName(), BLUE, this->getSignGrade(), BLUE, this->getExecGrade(), BLUE, FALSE_EMOJI);

	// std::cout << "Form Constructor called for " << YELLOW << this->getName() << RESET <<
	// ":\nsign grade : " << BLUE << this->getSignGrade() << RESET <<
	// "\nexecution grede : " << BLUE << this->getExecGrade() << RESET <<
	// "\nsigned : " << this->getSignedBool() << std::endl;
	// const int i = this->getSignGrade();
	// const int j = this->getExecGrade();

	const int i = this->getSignGrade();
	const int j = this->getExecGrade();
	if (i > 150 || j > 150)
		throw(Form::GradeTooLowException());
	else if (i < 1 || j < 1)
		throw(Form::GradeTooHighException());
}

Form &Form::operator=(const Form &assign)
{
	std::cout << ORANGE << "\n* Form Assignation operator called" << RESET << std::endl;
	if (this != &assign)
		return *this;
		// do nothing
	return *this;
}

Form::~Form(void)
{
	std::cout << RED << "* Form Deconstructor for " << this->getName() << " called" << RESET << std::endl;
}

void Form::doSign(Bureaucrat &human)
{
	if ((int)human.getGrade() > this->getSignGrade())
		throw(Bureaucrat::GradeTooLowException());
	else if (this->getSigned() == FALSE_EMOJI)
	{
		this->_signed = true;
		std::cout << BLACK << "Form has been signed by " << human.getName() << RESET << std::endl;
		return;
	}
	std::cout << RED << "Form is already signed by " << this->getName() << RESET << std::endl;
}

const std::string Form::getName(void) const
{
	return (this->_name);
}

const std::string Form::getSigned(void) const
{
	std::string str(FALSE_EMOJI);
	if (this->_signed)
		return (TRUE_EMOJI);
	return (str);
}

bool Form::getSignedBool(void) const
{
	return (this->_signed);
}

int Form::getSignGrade(void) const
{
	return (this->_sign_grade);
}

int Form::getExecGrade(void) const
{
	return (this->_exec_grade);
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low /!\\");
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high /!\\");
}

std::ostream &operator<<(std::ostream &o, Form *a)
{
	o << MAGENTA << "\n* Form --> " << a->getName() << "\nsign grade : " << a->getSignGrade() <<
	"\nexecution grade : " << a->getExecGrade() << "\nsigned : " <<
	a->getSigned() << RESET << std::endl;
	return (o);
}
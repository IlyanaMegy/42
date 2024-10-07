/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:41:35 by ilymegy           #+#    #+#             */
/*   Updated: 2024/09/23 15:41:38 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"

void print_infos(const std::string name, const std::string n_color, int sign_g, const std::string s_color, int exec_g, const std::string e_color, const std::string sign_emoji)
{
	std::cout << n_color  << "--> " << name << RESET <<
	"\nsign grade : " << s_color << sign_g << RESET <<
	"\nexecution grade : " << e_color << exec_g << RESET <<
	"\nsigned : " << sign_emoji << std::endl;
}

AForm::AForm(void): _name("default"), _signed(false), _sign_grade(150), _exec_grade(150)
{
	std::cout << "\n* Form Default Constructor called for " << std::endl;
	print_infos(this->getName(), YELLOW, this->getSignGrade(), YELLOW, this->getExecGrade(), YELLOW, FALSE_EMOJI);
}

AForm::AForm(AForm const &copy): _name(copy.getName() + "_copy"), _signed(false), _sign_grade(copy.getSignGrade()), _exec_grade(copy.getExecGrade())
{
	std::cout << ORANGE << "\n* Form Copy Constructor copied " << copy.getName() << 
	" into " << this->getName() << RESET << std::endl;
	*this = copy;
}

AForm::AForm(int sign_grade, int exec_grade): _name("default"), _signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	const int i = this->getSignGrade();
	const int j = this->getExecGrade();
	if (i > 150 || j > 150)
		throw(AForm::GradeTooLowException());
	else if (i < 1 || j < 1)
		throw(AForm::GradeTooHighException());
	std::cout << "\n* Form Constructor called for " << std::endl;
	print_infos(this->getName(), YELLOW, this->getSignGrade(), BLUE, this->getExecGrade(), BLUE, FALSE_EMOJI);
}

AForm::AForm(const std::string name): _name(name), _signed(false), _sign_grade(150), _exec_grade(150)
{
	std::cout << "\n* Form Constructor called for " << std::endl;
	print_infos(this->getName(), BLUE, this->getSignGrade(), YELLOW, this->getExecGrade(), YELLOW, FALSE_EMOJI);
}

AForm::AForm(const std::string name, int sign_grade, int exec_grade): _name(name), _signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	const int i = this->getSignGrade();
	const int j = this->getExecGrade();
	if (i > 150 || j > 150)
		throw(AForm::GradeTooLowException());
	else if (i < 1 || j < 1)
		throw(AForm::GradeTooHighException());
	std::cout << "\n* Form Constructor called for " << std::endl;
	print_infos(this->getName(), BLUE, this->getSignGrade(), BLUE, this->getExecGrade(), BLUE, FALSE_EMOJI);
}

AForm &AForm::operator=(const AForm &assign)
{
	if (this != &assign)
		return *this;
	return *this;
}

virtual AForm::~AForm(void)
{
	std::cout << RED << "* Form Deconstructor for " << this->getName() << " called" << RESET << std::endl;
}

void AForm::doSign(Bureaucrat &human)
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

virtual void AForm::execute(Bureaucrat const &executor) const
{
	(void)executor;
}

const std::string AForm::getName(void) const
{
	return (this->_name);
}

const std::string AForm::getSigned(void) const
{
	std::string str(FALSE_EMOJI);
	if (this->_signed)
		return (TRUE_EMOJI);
	return (str);
}

bool AForm::getSignedBool(void) const
{
	return (this->_signed);
}

int AForm::getSignGrade(void) const
{
	return (this->_sign_grade);
}

int AForm::getExecGrade(void) const
{
	return (this->_exec_grade);
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low /!\\");
};

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high /!\\");
};

const char *AForm::FormNotSignedException::what(void) const throw()
{
	return ("Form needs to be signed before executing");
};

std::ostream &operator<<(std::ostream &o, Form *a)
{
	o << MAGENTA << "\n* Form --> " << a->getName() << "\nsign grade : " << a->getSignGrade() <<
	"\nexecution grade : " << a->getExecGrade() << "\nsigned : " <<
	a->getSigned() << RESET << std::endl;
	return (o);
}

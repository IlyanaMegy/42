/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:38:41 by ilymegy           #+#    #+#             */
/*   Updated: 2024/09/23 15:38:46 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

const std::string validName(const std::string& name)
{
	if (name.empty())
		throw Bureaucrat::InvalidNameException();
	for (size_t i = 0; i < name.length(); ++i)
	{
		if (std::isdigit(name[i]))
			throw Bureaucrat::InvalidNameException();
	}
	return (name);
}

Bureaucrat::Bureaucrat(): _name("default"), _grade(150)
{}

Bureaucrat::Bureaucrat(const Bureaucrat &copy): _name(copy.getName() + "_copy"), _grade(copy._grade)
{}

Bureaucrat::Bureaucrat(int grade): _name("default"), _grade(setGrade(grade))
{}

Bureaucrat::Bureaucrat(const std::string name): _name(validName(name)), _grade(150)
{}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(validName(name)), _grade(setGrade(grade))
{}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	if (this != &src && validName(src._name)[0])
		setGrade(src._grade);
	return *this;
}

Bureaucrat::~Bureaucrat()
{}

void Bureaucrat::incrementGrade()
{
	if (this->_grade == 1)
		throw (Bureaucrat::GradeTooHighException());
	else
		this->_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade == 150)
		throw (Bureaucrat::GradeTooLowException());
	else
		this->_grade++;
}

void	Bureaucrat::signForm(AForm &form)
{
	form.doSign(*this);
}

void	Bureaucrat::executeForm(AForm &form)const
{
	try
	{
        form.execute(*this);
        std::cout << this->_name << " executed " << form.getName() << std::endl;
    }
	catch (std::exception &e)
	{
        std::cout << this->_name << " couldn’t execute " << form.getName() << " because " << e.what() << std::endl;
    }
}

const std::string Bureaucrat::getName(void)const
{
	return (this->_name);
}

size_t Bureaucrat::getGrade(void)const
{
	return (this->_grade);
}

size_t Bureaucrat::setGrade(int grade)
{
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	else if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else
		this->_grade = grade;
	return this->_grade;
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low /!\\");
};

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high /!\\");
};

const char *Bureaucrat::InvalidNameException::what() const throw()
{
	return "Invalid name: Name must not be empty and must not contain digits. /!\\";
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat const *a)
{
	o << BLACK << "\n* Bureaucrat " << a->getName() << "\n  grade : " << a->getGrade() << RESET << std::endl;
	return (o);
}

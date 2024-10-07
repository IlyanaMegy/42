/* *************************************************************************\n* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:46:51 by ilymegy           #+#    #+#             */
/*   Updated: 2024/09/17 16:46:53 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name("default"), _grade(150)
{
	std::cout << "\n* Bureaucrat Default Constructor just created " << this->getName() << " with grade of " << this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy): _name(copy.getName() + "_copy"), _grade(copy._grade)
{
	std::cout << "\n* Bureaucrat Copy Constructor copied " << copy.getName() << " into " << this->getName() << std::endl;
}

Bureaucrat::Bureaucrat(int grade): _name("default")
{
	std::cout << "\n* Bureaucrat Constructor just created " << this->getName() << " with grade of " << grade << std::endl;
	this->setGrade(grade);
}

Bureaucrat::Bureaucrat(const std::string name): _name(name), _grade(150)
{
	std::cout << "\n* Bureaucrat Constructor just created " << this->getName() << " with grade of " << this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name)
{
	std::cout << "\n* Bureaucrat Constructor just created " << this->getName() << " with grade of " << grade << std::endl;
	this->setGrade(grade);
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &assign)
{
	std::cout << "\n* Bureaucrat Assignation operator called" << std::endl;
	if (this != &assign)
		this->_grade = assign.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << RED << "* Bureaucrat Deconstructor for " << this->getName() << " called" << RESET << std::endl;
}

void Bureaucrat::incrementGrade(void)
{
	if (this->_grade == 1)
		throw (Bureaucrat::GradeTooHighException());
	else
		this->_grade--;
}

void Bureaucrat::decrementGrade(void)
{
	if (this->_grade == 150)
		throw (Bureaucrat::GradeTooLowException());
	else
		this->_grade++;
}

void	Bureaucrat::signForm(Form &form)
{
	form.doSign(*this);
}

const std::string Bureaucrat::getName(void)const
{
	return (this->_name);
}

size_t Bureaucrat::getGrade(void)const
{
	return (this->_grade);
}

void Bureaucrat::setGrade(int grade)
{
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	else if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else
		this->_grade = grade;	
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low /!\\");
};

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high /!\\");
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat const *a)
{
	o << BLACK << "\n* Bureaucrat --> " << a->getName() << "\ngrade : " << a->getGrade() << RESET << std::endl;
	return (o);
}

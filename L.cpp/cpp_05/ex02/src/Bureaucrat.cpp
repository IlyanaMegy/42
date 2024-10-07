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

void print_infos(const std::string name, int grade)
{
	std::cout << GREEN << "\n* BIG CEO just enrolled Bureaucrat " << name <<
	" into the company\n\t\tstarting with grade of " << grade << RESET << std::endl;
}

Bureaucrat::Bureaucrat(void): _name("default"), _grade(150)
{
	std::cout << GREEN << "\n* BIG CEO just enrolled Default Bureaucrat " << this->getName() <<
	" into the company\n\t\tstarting with grade of " <<this->getGrade() << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy): _name(copy.getName() + "_copy"), _grade(copy.getGrade())
{
	print_infos(this->getName(), this->getGrade());
}

Bureaucrat::Bureaucrat(int grade): _name("default")
{
	print_infos(this->getName(), grade);
	try
	{
		this->setGrade(grade);
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "\033[33mConstructing " << this->getName() <<
		" failed: " << e.what() << std::endl <<
		"Grade now set to 1" << "\033[0m" << std::endl;
		this->setGrade(1);
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "\033[33mConstructing " << this->getName() <<
		" failed: " << e.what() << std::endl <<
		"Grade now set to 150" << "\033[0m" << std::endl;
		this->setGrade(150);
	}
}

Bureaucrat::Bureaucrat(const std::string name): _name(name), _grade(150)
{
	print_infos(this->getName(), this->getGrade());
}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name)
{
	print_infos(this->getName(), grade);
	try
	{
		this->setGrade(grade);
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "\033[33mConstructing " << this->getName() <<
		" failed: " << e.what() << std::endl <<
		"Grade now set to 1" << "\033[0m" << std::endl;
		this->setGrade(1);
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "\033[33mConstructing " << this->getName() <<
		" failed: " << e.what() << std::endl <<
		"Grade now set to 150" << "\033[0m" << std::endl;
		this->setGrade(150);
	}
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &assign)
{
	std::cout << BLACK << "\n* Bureaucrat Assignation operator called" << RESET << std::endl;
	if (this != &assign)
		this->_grade = assign.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << RED << "* Bureaucrat " << this->getName() << " has been fired." << RESET << std::endl;
}

void Bureaucrat::incrementGrade(void)
{
	if (this->_grade < 1)
		throw(GradeTooHighException());
	std::cout << CYAN <<"\n* Bureaucrat " << this->getName() << " just upgraded from " <<
		this->_grade << " to " << this->_grade - 1 << " 🤙" << RESET << std::endl;
	this->_grade--;
	if (this->_grade == 1)
		std::cout << CYAN << "* Bureaucrat " << this->getName() << " just became BIG CEO of the company 😎" << RESET << std::endl;
}

void Bureaucrat::decrementGrade(void)
{
	if (this->_grade > 150)
		throw(GradeTooLowException());
	std::cout << BLUE <<"\n* Bureaucrat " << this->getName() << " just downgraded from " <<
		this->_grade << " to " << this->_grade + 1 << "... 🥺" << RESET << std::endl;
	this->_grade++;
	if (this->_grade == 150)
		std::cout << ORANGE << "* Bureaucrat " << this->getName() << " just became the toilet paper of whole the company 😎" << RESET << std::endl;
}

void Bureaucrat::signForm(Form &form)
{
	form.doSign(*this);
}

void	Bureaucrat::executeForm(Form &form)const
{
	// if ((int)this->getGrade() > form.getExecGrade())
	// 	throw (Bureaucrat::GradeTooLowException());
	// else
		form.execute(*this);
}

const std::string Bureaucrat::getName(void) const
{
	return (this->_name);
}

size_t Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void Bureaucrat::setGrade(int grade)
{
	if (grade > 150)
		throw(GradeTooLowException());
	else if (grade < 1)
		throw(GradeTooHighException());
	this->_grade = grade;
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("/!\\ Grade is too low /!\\");
};

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("/!\\ Grade is too high /!\\");
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat const *a)
{
	o << BLACK << "\n* Bureaucrat --> " << a->getName() << "\n\tgrade : " << a->getGrade() << RESET << std::endl;
	return (o);
}

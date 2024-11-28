/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:33:59 by ilymegy           #+#    #+#             */
/*   Updated: 2024/10/07 14:34:03 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"

static std::string verifTarget(std::string t)
{
	if (t.empty())
	{
		std::cout << "Error: Target must be specified '" << t << "' is not recognized." << std::endl;
        throw std::invalid_argument("Target must be specified");
	}
	return (t);
}

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
	std::cout << "ShrubberyCreationForm Default Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137), _target(verifTarget(target))
{
	std::cout << "ShrubberyCreationForm for target " << CYAN << this->getTarget() << RESET << " called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src): AForm("ShrubberyCreationForm", 145, 137), _target(verifTarget(src.getTarget()))
{
	std::cout << ORANGE << "ShrubberyCreationForm Copy Constructor called to copy " << src.getName() <<
	" into " << this->getName() << RESET << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << RED << "ShrubberyCreationForm Destructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src)
{
    std::cout << "ShrubberyCreationForm Assignation operator called" << std::endl;
	if (this != &src)
		this->_target = verifTarget(src._target);
	return *this;
}

void ShrubberyCreationForm::executeAction() const
{
    std::string filename = _target + "_shrubbery";
    std::ofstream outfile (this->getTarget().append("_shrubbery").c_str());
    if (outfile.is_open())
    {
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
    else
        std::cerr << "Failed to open file: " << filename << "\n";
}

std::string	ShrubberyCreationForm::getTarget()const
{
	return (this->_target);
}

std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm *a)
{
	o << MAGENTA << "\n* Form " << a->getName() << "\n  sign grade : " << a->getSignGrade() <<
	"\n  execution grade : " << a->getExecGrade() << "\n  signed : " << a->getIsSigned() << RESET << std::endl;
	return (o);
}

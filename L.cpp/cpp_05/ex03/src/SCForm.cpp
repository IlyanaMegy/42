/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SCForm.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 21:00:33 by ilymegy           #+#    #+#             */
/*   Updated: 2024/10/17 21:00:34 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/SCForm.hpp"

std::string verifTarget(std::string t)
{
	if (t.empty())
	{
		std::cout << "Error: Target must be specified '" << this->_target << "' is not recognized." << std::endl;
        throw std::invalid_argument("Target must be specified");
	}
	return (t);	
}

SCForm::SCForm() : AForm("ShrubberyCreationForm", 145, 137), _target("defaultS")
{}

SCForm::SCForm(SCForm const &src) : AForm("ShrubberyCreationForm", 145, 137), _target(verifTarget(src.getTarget()))
{}

SCForm::SCForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(verifTarget(target))
{}

SCForm &SCForm::operator=(SCForm const &src)
{
	if (this != &src)
		this->_target = verifTarget(src.getTarget());
	return (*this);
}

SCForm::~SCForm()
{}

std::string SCForm::getTarget() const
{
	return (this->_target);
}

void SCForm::executeAction() const
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

std::ostream &operator<<(std::ostream &o, SCForm *a)
{
	o << MAGENTA << "\n* Form " << a->getName() << "\n  sign grade : " << a->getSignGrade() <<
	"\n  execution grade : " << a->getExecGrade() << "\n  signed : " << a->getIsSigned() << RESET << std::endl;
	return (o);
}

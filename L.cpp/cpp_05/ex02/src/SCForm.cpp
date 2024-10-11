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
	if (this->_target.empty())
    {
        std::cout << "Error: Target must be specified '" << this->_target << "' is not recognized." << std::endl;
        throw std::invalid_argument("Target must be specified");
    }
	std::cout << "ShrubberyCreationForm for target " << CYAN << this->getTarget() << RESET << " called" << std::endl;
}

SCForm::SCForm(SCForm const &src): AForm("ShrubberyCreationForm", 145, 137), _target(src.getTarget())
{
	if (this->_target.empty())
    {
        std::cout << "Error: Target must be specified '" << this->_target << "' is not recognized." << std::endl;
        throw std::invalid_argument("Target must be specified");
    }
	std::cout << ORANGE << "ShrubberyCreationForm Copy Constructor called to copy " << src.getName() <<
	" into " << this->getName() << RESET << std::endl;
}

SCForm::~SCForm()
{
	std::cout << RED << "RobotomyRequestForm Destructor called" << std::endl;
}

SCForm &SCForm::operator=(SCForm const &src)
{
	std::cout << "ShrubberyCreationForm Assignation operator called" << std::endl;
	if (this != &src)
		return *this;
	return *this;
}

// void SCForm::executeAction(Bureaucrat const &executor)const
// {
// 	if (executor.getGrade() > this->getExecGrade())
// 		throw (Bureaucrat::GradeTooLowException());
// 	else if (this->getIsSignedBool() == false)
// 		throw (AForm::FormNotSignedException());
// 	else
// 	{
// 		std::ofstream outfile (this->getTarget().append("_shrubbery").c_str());
// 		for (int i = 0; i < 5; i++)
// 		{
// 			outfile <<
// 			"         v" << std::endl <<
// 			"        >X<" << std::endl <<
// 			"         A" << std::endl <<
// 			"        d$b" << std::endl <<
// 			"      .d\\$$b." << std::endl <<
// 			"    .d$i$$\\$$b." << std::endl <<
// 			"       d$$@b" << std::endl <<
// 			"      d\\$$$ib" << std::endl <<
// 			"    .d$$$\\$$$b" << std::endl <<
// 			"  .d$$@$$$$\\$$ib." << std::endl <<
// 			"      d$$i$$b" << std::endl <<
// 			"     d\\$$$$@$b" << std::endl <<
// 			"  .d$@$$\\$$$$$@b." << std::endl <<
// 			".d$$$$i$$$\\$$$$$$b." << std::endl <<
// 			"        ###" << std::endl <<
// 			"        ###" << std::endl <<
// 			"        ###" << std::endl <<
// 		std::endl;
// 		}
// 		outfile.close();
// 	}
// }


void SCForm::executeAction() const
{
    // std::string baseFilename = _target + "_shrubbery";
    // std::string filename = baseFilename;
    // struct stat fileStat;

    // /**
    //  * Check if base file exists and its permissions
    // */
    // if (stat(filename.c_str(), &fileStat) == 0 && (fileStat.st_mode & S_IWUSR) == 0)
    // {
    //     /** 
    //     * Fichier existant et non accessible en écriture
    //     */
    //     std::cout << "File " << baseFilename << " already exists and is not writable. \n";
    //     int counter = 1;
    //     bool fileFound = false;

    //     while (!fileFound)
    //     {
    //         std::ostringstream oss;
    //         oss << baseFilename << "_" << counter++;
    //         filename = oss.str();
            
    //         /**
    //          * Check if new filename exists
    //         */
    //         if (stat(filename.c_str(), &fileStat) == 0)
    //         {
    //             /**
    //              * File exists, check its permissions
    //             */
    //             if ((fileStat.st_mode & S_IWUSR) == 0)
    //                 std::cout << "File " << filename << " already exists and is not writable. \nTrying next suffix.\n";
    //             else
    //             {
    //                 /**
    //                  * File exists and is writable
    //                 */
    //                 fileFound = true;
    //             }
    //         }
    //         else
    //         {
    //             /**
    //              * File does not exist, can be created
    //             */
    //             fileFound = true;
    //         }
    //     }
    //     std::cout << "Creating a new file with suffix _" << counter - 1 << std::endl;
    // }

    // std::ofstream file(filename.c_str());
    // if (file.is_open())
    // {
    //     file << "      /\\\n";
    //     file << "     /\\*\\\n";
    //     file << "    /\\O\\*\\\n";
    //     file << "   /*/\\/\\/\\\n";
    //     file << "  /\\O\\/\\*\\/\\\n";
    //     file << " /\\*\\/\\*\\/\\/\\\n";
    //     file << "/\\O\\/\\/*/\\/O/\\\n";
    //     file << "      ||\n";
    //     file << "      ||\n";
    //     file.close();
    //     std::cout << "File " << filename << " created successfully." << std::endl;
    // }
    // else
    //     std::cerr << "Failed to open file: " << filename << "\n";

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


std::string	SCForm::getTarget()const
{
	return (this->_target);
}

std::ostream &operator<<(std::ostream &o, SCForm *a)
{
	o << MAGENTA << "\n* Form " << a->getName() << "\n  sign grade : " << a->getSignGrade() <<
	"\n  execution grade : " << a->getExecGrade() << "\n  signed : " << a->getIsSigned() << RESET << std::endl;
	return (o);
}

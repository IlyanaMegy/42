/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GodMode.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:17:35 by ilymegy           #+#    #+#             */
/*   Updated: 2024/09/24 14:17:36 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/GodMode.hpp"

GodMode::GodMode(void)
{
	_full = false;
	_index = 0;
	return;
}

GodMode::~GodMode(void)
{
	return;
}

void GodMode::greetings(const std::string greetings)
{
	std::cout << CYAN << greetings << " GOD.\nWhat will be your instruction ?" << RESET << std::endl;
}

void GodMode::show_cmds(void)
{
	std::cout << CYAN << "\n\t\t-- GODMODE instructions --" << RESET << std::endl;
	std::cout << CYAN << "\n\n\tnew, n" << RESET << "\t\tadd a new human to this company" << std::endl;
	std::cout << CYAN << "\n\tshow, s" << RESET << "\t\tshow humans of this company" << std::endl;
	std::cout << CYAN << "\n\thelp, h" << RESET << "\t\tshow GODMODE possible instructions" << std::endl;
	std::cout << CYAN << "\n\tdowngrade, d" << RESET << "\tdowngrade one human's grade" << std::endl;
	std::cout << CYAN << "\n\tupgrade, u" << RESET << "\tupgrade one human's grade" << std::endl;
	std::cout << CYAN << "\n\texit" << RESET << "\t\texit GODMODE\n\n" << std::endl;
}

const std::string addContent(int step)
{
	bool ok = false;
	std::string content;
	while (!std::getline(std::cin, content) || !ok)
	{
		if (std::cin.eof() == true)
		{
			std::cout << "Ok bye." << std::endl;
			return NULL;
		}
		else if (step == 1 && (content.length() > 15 || content.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ -_}{=+!@#$%^&*()~`?><:;,./|0123456789") == std::string::npos))
		{
			content.clear();
			std::cout << RED << "Invalid name" << RESET << std::endl;
			std::cout << "name : " << std::endl;
		}
		else if (step == 2 && (content.length() > 3 || content[0] == '0' || content.find_first_not_of("0123456789") == std::string::npos))
		{
			content.clear();
			std::cout << RED << "Invalid grade" << RESET << std::endl;
			std::cout << "grade : " << std::endl;
		}
		else if (content[content.length() - 1] == '\n')
			ok = true;
	}
	std::cout << content << std::endl;
	if (content[0] == '\n')
		return NULL;
	return (content);
}

bool creating()
{
	std::cout << "name : " << std::endl;
	const std::string name = addContent(1);
	std::cout << "grade : " << std::endl;
	std::string grade = addContent(2);
	if (name[0])
	{
		if (grade[0])
		{
			try
			{
				Bureaucrat New(name, atoi(grade.c_str()));
			}
			catch(const std::exception &e)
			{
				std::cerr << "Exception caught: " << RED << e.what() << RESET << std::endl;
			}
		}
		else
		{
			try
			{
				Bureaucrat New(name);
			}
			catch(const std::exception &e)
			{
				std::cerr << "Exception caught: " << RED << e.what() << RESET << std::endl;
			}
		}
	}
	else if (grade[0])
	{
		try
		{
			Bureaucrat New(atoi(grade.c_str()));
		}
		catch(const std::exception &e)
		{
			std::cerr << "Exception caught: " << RED << e.what() << RESET << std::endl;
		}
	}
	else
	{
		try
		{
			Bureaucrat();
		}
		catch(const std::exception &e)
		{
			std::cerr << "Exception caught: " << RED << e.what() << RESET << std::endl;
		}
	}
	return true;
}

void GodMode::new_human(void)
{
	std::string input;
	if (!this->_full)
	{
		if (this->_humans[this->_index].creating())
		{
			if ( this->_index == 199)
				this->_full = true;
			else
				this->_index++;
		}
	}
	else
	{
		int replace_at = rand() % 200;
		std::cout << "Too much humans in the company !\nRandom human n°" << replace_at << " will now get fired." << std::endl;
		this->_humans[replace_at - 1].creating();
	}
}

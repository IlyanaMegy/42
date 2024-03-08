/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:49:05 by ilymegy           #+#    #+#             */
/*   Updated: 2024/03/04 17:49:06 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Contact.hpp"

Contact::Contact(void)
{
	for (int i = FirstName; i < DarkestSecret; i++)
		this->_infos[i] = std::string();
	return ;
}

Contact::~Contact(void)
{
	return ;
}

std::string Contact::_fields_name[5] =
	{
		"First name",
		"Last name",
		"Nickname",
		"Phone number",
		"Darkest secret"};

void Contact::get_contact(int index) const
{
	std::cout << "|" << std::setw(10) << index;
	for (int i = FirstName; i <= Nickname; i++)
	{
		std::cout << "|";
		if (this->_infos[i].length() > 10)
			std::cout << this->_infos[i].substr(0, 9) << ".";
		else
			std::cout << std::setw(10) << this->_infos[i];
	}
	std::cout << "|" << std::endl;
}

static bool	checkContent(std::string const &str)
{
	return str.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ -_}{=+!@#$%^&*()~`?><:;,./|0123456789") ==
		std::string::npos;
}

bool Contact::set_contact(void)
{
	for (int i = FirstName; i <= DarkestSecret; i++)
	{
		std::cout << "Enter the " << Contact::_fields_name[i] << " :\n";

		while (!(std::getline(std::cin, this->_infos[i])) || this->_infos[i].length() == 0 || !checkContent(this->_infos[i]))
		{
			if (std::cin.eof() == true)
			{
				std::cout << "Ok bye." << std::endl;
				std::exit(0);
			}
			else if (this->_infos[i].length() == 0)
			{
				this->_infos[i].clear();
				std::cout << "Empty entry not allowed !" << std::endl;
				std::cout << "Enter the " << Contact::_fields_name[i] << " :\n";
			}
			else if (! checkContent(this->_infos[i]))
			{
				this->_infos[i].clear();
				std::cout << "This entry is not allowed !" << std::endl;
				std::cout << "Enter the " << Contact::_fields_name[i] << " :\n";
			}
		}
	}
	std::cout << "New friend added successfully." << std::endl;
	return (true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:14:37 by ilymegy           #+#    #+#             */
/*   Updated: 2023/11/22 14:14:39 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Contact.hpp"

std::string Contact::_fields_name[5] =
	{
		"First name",
		"Last name",
		"Nickname",
		"Phone number",
		"Darkest secret"};

Contact::Contact()
{
	for (int i = FirstName; i < DarkestSecret; i++)
		this->_infos[i] = std::string();
	return ;
}

Contact::~Contact()
{
	return ;
}

bool Contact::set_contact()
{
	for (int i = FirstName; i < DarkestSecret; i++)
	{
		std::cout << "Enter the " << Contact::_fields_name[i] << ":\n";
		while (!(std::getline(std::cin, this->_infos[i]))
			|| this->_infos[i].length() == 0)
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
				std::cout << "Enter the " << Contact::_fields_name[i] << ":\n";
			}
		}
	}
	std::cout << "Contact added successfully." << std::endl;
	return (true);
}

void Contact::get_contact(int idx) const
{
	std::cout << "|" << std::setw(10) << idx;
	for (int i = FirstName; i <= NickName; i++)
	{
		std::cout << "|";
		if (this->_infos[i].length() > 10)
			std::cout << this->_infos[i].substr(0, 9) << ".";
		else
			std::cout << std::setw(10) << this->_infos[i];
	}
	std::cout << "|" << std::endl;
}

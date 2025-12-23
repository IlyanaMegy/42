/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:48:57 by ilymegy           #+#    #+#             */
/*   Updated: 2024/03/04 17:48:59 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	_full = false;
	_index = 0;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void PhoneBook::show_instruction(void)
{
	std::cout << "Enter an instruction [ADD, SEARCH, EXIT]:" << std::endl;
}

void PhoneBook::get_infos(void) const
{
	int i;
	if (this->_index == 0)
		std::cout << "No friend saved yet. What about you add some before searching for one ?" << std::endl;
	else
	{
		std::string input;
		std::cout << "What is the index of that \"friend\" you want infos from ? (or press 0 to quit)\nIndex: ";
		while (!(std::getline(std::cin, input)) || input.length() > 1 || input.compare("0") < 0 || input.compare("8") > 0 || (std::atoi(input.c_str()) - 1 >= this->_index && this->_full == false))
		{
			if (std::cin.eof() == true)
			{
				std::cout << "Ok bye." << std::endl;
				std::exit(0);
			}
			else if (input.length() > 1 || input.compare("0") < 0 || input.compare("8") > 0)
			{
				std::cin.clear();
				std::cout << "Ok so... you are supposed to enter ONE digit from 1 to 8 right now.\n";
				std::cout << "Again. What is the index of that \"friend\" you want informations from ? (or press 0 to quit.)\nIndex: ";
			}
			else if (std::atoi(input.c_str()) - 1 >= this->_index && this->_full == false)
			{
				std::cout << "You only have " << this->_index << " friend(s) saved here." << std::endl;
				std::cin.clear();
				std::cout << "Again. What is the index of that \"friend\" you want informations from ? (or press 0 to quit.)\nIndex: ";
			}
		}
		i = std::atoi(input.c_str());
		if (i > 0)
		{
			std::cout << "|-------------------------------------------|" << std::endl;
			std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
			std::cout << "|----------|----------|----------|----------|" << std::endl;
			this->_contacts[i - 1].get_contact(i);
			std::cout << "|-------------------------------------------|" << std::endl;
		}
		else
			std::cout << "Good. Exiting search mode now." << std::endl;
	}
}

void PhoneBook::set_infos(void)
{
	std::string input;
	if (this->_full == false)
	{
		std::cout << "Inventing friend #" << this->_index + 1 << std::endl;
		if (this->_contacts[this->_index].set_contact() == true)
		{
			if (this->_index == 7)
				this->_full = true;
			else
				this->_index++;
		}
	}
	else
	{
		std::cout << "The Phonebook is full... First friend added will now be instantly erased." << std::endl;
		for (int i = 1; i < 8; i++)
			this->_contacts[i - 1] = this->_contacts[i];
		std::cout << "Inventing friend #8" << std::endl;
		this->_contacts[this->_index].set_contact();
	}
}

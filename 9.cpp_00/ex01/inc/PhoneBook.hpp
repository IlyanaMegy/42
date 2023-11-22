/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:20:03 by ilymegy           #+#    #+#             */
/*   Updated: 2023/11/22 14:20:05 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"
# include <cstdlib>
# include <iomanip>
# include <string>

class PhoneBook
{
  private:
	Contact _contacts[8];
	bool _full;
	int _index;

  public:
	PhoneBook(void);
	~PhoneBook(void);
	void set_information(void);
	void get_information(void) const;
	void show_instruction(void);
};

#endif

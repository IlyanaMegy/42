/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:48:48 by ilymegy           #+#    #+#             */
/*   Updated: 2024/03/04 17:48:50 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
# include <iomanip>
# include <cstdlib>

class PhoneBook
{
  private:
	Contact _contacts[8];
	int _index;
	bool _full;

  public:
	PhoneBook(void);
	~PhoneBook(void);
	void show_instruction(void);
	void set_infos(void);
	void get_infos(void) const;
};
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:48:42 by ilymegy           #+#    #+#             */
/*   Updated: 2024/03/04 17:48:43 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>
# include <iomanip>
# include <cstdlib>

class Contact
{
  private:
	static std::string _fields_name[5];
	std::string _infos[11];
	enum	Field
	{
		FirstName = 0,
		LastName,
		Nickname,
		PhoneNumber,
		DarkestSecret
	};

  public:
	Contact(void);
	~Contact(void);
	void get_contact(int i) const;
	bool set_contact(void);
};
#endif

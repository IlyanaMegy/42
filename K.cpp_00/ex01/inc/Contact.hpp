/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:19:52 by ilymegy           #+#    #+#             */
/*   Updated: 2023/11/22 14:19:54 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <cstdlib>
# include <iomanip>
# include <iostream>
# include <string>

class Contact
{
  private:
	static std::string _fields_name[5];
	std::string _infos[11];
	enum	Field
	{
		FirstName = 0,
		LastName,
		NickName,
		PhoneNumber,
		DarkestSecret
	};

  public:
	Contact(void);
	~Contact(void);
	bool set_contact(void);
	void get_contact(int idx) const;
};

#endif

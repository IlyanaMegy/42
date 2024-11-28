/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:36:21 by ilymegy           #+#    #+#             */
/*   Updated: 2024/11/26 17:36:22 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <algorithm>
# include <exception>

class NotFoundException : public std::exception
{
  public:
	virtual const char *what() const throw()
	{
		return ("Number not found");
	}
};

template <typename T>
typename T::iterator easyfind(T &tab, int nb)
{
	typename T::iterator i = std::find(tab.begin(), tab.end(), nb);
	if (i == tab.end())
		throw NotFoundException();
	return (i);
}
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:50:47 by ilymegy           #+#    #+#             */
/*   Updated: 2024/03/11 13:50:48 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iomanip>
# include <iostream>

class Weapon
{
  private:
	std::string _type;

  public:
	Weapon(const std::string &weapon);
	~Weapon(void);
	std::string getType(void) const;
	void setType(const std::string &weapon);
};

#endif

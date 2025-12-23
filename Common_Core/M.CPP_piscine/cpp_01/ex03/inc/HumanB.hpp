/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:50:30 by ilymegy           #+#    #+#             */
/*   Updated: 2024/03/11 13:50:32 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
# include "Weapon.hpp"

class HumanB
{
  private:
	std::string _name;
	Weapon *_weapon;

  public:
	HumanB(std::string name);
	~HumanB(void);
	void setWeapon(Weapon &weapon);
	void attack(void);
};

#endif

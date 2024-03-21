/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:37:14 by ilymegy           #+#    #+#             */
/*   Updated: 2024/03/21 15:37:15 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iomanip>
# include <iostream>

class ClapTrap
{
  private:
	std::string _name;
	unsigned int _health;
	unsigned int _energy;
	unsigned int _attackDamage;

  public:
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const &copy);
	ClapTrap &operator=(ClapTrap const &assign);
	~ClapTrap(void);

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 18:30:38 by ilymegy           #+#    #+#             */
/*   Updated: 2024/03/28 18:30:39 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
  private:
	bool _gate;

  public:
  	ScavTrap(void);
	ScavTrap(const std::string name);
	ScavTrap(ScavTrap const &copy);
	ScavTrap &operator=(ScavTrap const &assign);
	~ScavTrap();

	void attack(const std::string &target);
	void guardGate();
};

#endif

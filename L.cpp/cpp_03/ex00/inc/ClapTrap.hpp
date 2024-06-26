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
# include <climits>
# include <iomanip>
# include <iostream>

# define BLACK "\033[30m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"
# define UNDERLINE "\033[4m"
# define RESET "\033[0m"

class ClapTrap
{
  private:
	std::string _name;
	unsigned int _health;
	unsigned int _energy;
	unsigned int _attackDamage;

  public:
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const &copy);
	ClapTrap &operator=(ClapTrap const &assign);
	~ClapTrap(void);

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void showStats(void);
};

#endif

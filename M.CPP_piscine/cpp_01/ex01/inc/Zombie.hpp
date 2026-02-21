/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:45:15 by ilymegy           #+#    #+#             */
/*   Updated: 2024/03/08 17:45:17 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iomanip>
# include <iostream>
# include <string>

class Zombie
{
  private:
	std::string _name;

  public:
	Zombie(void);
	~Zombie(void);
	void annonce(void) const;
	void set_name(std::string name);
};

Zombie	*zombieHorde(int N, std::string name);
#endif

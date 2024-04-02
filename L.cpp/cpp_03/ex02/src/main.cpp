/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 18:30:55 by ilymegy           #+#    #+#             */
/*   Updated: 2024/03/28 18:30:56 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FragTrap.hpp"
#include "../inc/ScavTrap.hpp"

int	main(void)
{
	std::cout << "### TESTING CLAPTRAP ###\n" << std::endl;
	{
		std::cout << "Constructing" << std::endl;
		ClapTrap a("Robot A");
		ClapTrap b("Robot B");
		std::cout << "\nTesting" << std::endl;
		a.attack("some other robot");
		a.takeDamage(10);
		a.takeDamage(10);
		a.beRepaired(5);
		a.attack("some other other robot");
		b.beRepaired(3);
		for (int i = 0; i < 12; i++)
			b.attack("B-clone");
		b.beRepaired(3);
		std::cout << "Deconstructing" << std::endl;
	}
	std::cout << "\n\n### TESTING SCAVTRAP ###\n" << std::endl;
	{
		std::cout << "Constructing" << std::endl;
		ScavTrap c("Robot C");
		ScavTrap d("Robot D");
		std::cout << "\nTesting" << std::endl;
		c.attack("CloneTrap");
		for (int i = 0; i < 50; i++)
		{
			if (i%10 == 0)
				c.showStats();
			c.attack("CloneTrap");
		}
		c.beRepaired(22);
		c.takeDamage(21);
		c.beRepaired(22);
		c.guardGate();
		c.guardGate();
		d.attack("D-clone");
		d.takeDamage(101);
		d.takeDamage(15);
		d.attack("ScavTrap-clone");
		std::cout << "Deconstructing" << std::endl;
	}
	std::cout << "\n\n### TESTING FRAGTRAP ###\n" << std::endl;
	{
		std::cout << "Constructing" << std::endl;
		FragTrap e("Robot E");
		FragTrap f("Robot F");
		std::cout << "\nTesting" << std::endl;
		e.attack("CloneTrap");
		for (int i = 0; i < 50; i++)
		{
			if (i%10 == 0)
				e.showStats();
			e.attack("CloneTrap");
			e.highFivesGuys();
		}
		e.beRepaired(22);
		e.takeDamage(21);
		e.beRepaired(22);
		f.highFivesGuys();
		f.highFivesGuys();
		f.attack("F-clone");
		f.takeDamage(101);
		f.takeDamage(15);
		f.attack("ScavTrap-clone");
		std::cout << "Deconstructing" << std::endl;
	}
	return (0);
}

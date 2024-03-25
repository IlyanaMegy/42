/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:36:34 by ilymegy           #+#    #+#             */
/*   Updated: 2024/03/21 15:36:35 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

int	main(void)
{
	ClapTrap a("Main");
	ClapTrap b("Second");
	a.attack("some robot");
	a.takeDamage(1);
	a.takeDamage(10);
	a.beRepaired(5);
	a.showStats();
	b.showStats();
	a.attack("some other robot");
	b.beRepaired(3);
	b.showStats();
	for (int i = 0; i < 12; i++)
		b.attack("Second-clone");
	b.beRepaired(3);
	return (0);
}

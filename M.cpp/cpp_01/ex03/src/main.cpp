/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:49:47 by ilymegy           #+#    #+#             */
/*   Updated: 2024/03/11 13:49:50 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Weapon.hpp"
#include "../inc/HumanA.hpp"
#include "../inc/HumanB.hpp"

int	main(void)
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
		std::cout << std::endl;		
		Weapon gun = Weapon("crude spiked gun");
		HumanB jim("Jim");
		jim.setWeapon(gun);
		jim.attack();
		gun.setType("some other type of gun");
		jim.attack();
		std::cout << std::endl;
	}
	{
		Weapon *weap = NULL;
		HumanB humain("Humain");
		humain.setWeapon(*weap);
		humain.attack();
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:45:56 by ilymegy           #+#    #+#             */
/*   Updated: 2024/03/08 17:45:57 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

int	main(void)
{
	int		count;
	Zombie	*horde;

	count = 10;
	horde = zombieHorde(count, "dead people");
	if (!horde)
		return (1);
	for (int i = 0; i < count; ++i)
		horde[i].annonce();
	delete[] horde;
	std::cout << "" << std::endl;

	horde = zombieHorde(1, "Lonely zombie");
	if (!horde)
		return (1);
	horde[0].annonce();
	delete[] horde;
	std::cout << "" << std::endl;

	horde = zombieHorde(0, "Failed one");
	return (0);
}

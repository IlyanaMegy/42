/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:40:11 by ilymegy           #+#    #+#             */
/*   Updated: 2024/03/08 16:40:12 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

int main(void)
{
	Zombie *zombie = newZombie("normal zombie");
	randomChump("random zombie");
	delete zombie;
	return (0);
}

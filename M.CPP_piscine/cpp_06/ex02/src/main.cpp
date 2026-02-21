/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:01:26 by ilymegy           #+#    #+#             */
/*   Updated: 2024/11/26 15:01:28 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"
#include "../inc/style.hpp"
#include <stdlib.h>

Base*	generate(void)
{
	int	choice = rand() % 3;

	switch (choice)
	{
		case (0): return new A();
		case (1): return new B();
		default: return new C();
	}
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p) != NULL) std::cout << BLUE "- A -" RESET << std::endl;
	else if (dynamic_cast<B*>(p) != NULL) std::cout << CYAN "- B -" RESET << std::endl;
	else if (dynamic_cast<C*>(p) != NULL) std::cout << MAGN "- C -" RESET << std::endl;
}

void	identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << LIME "- A -" RESET << std::endl;
	}
	catch (std::exception &e) { std::cout << REDD << "NOT A" << std::endl; }
	
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << LIME "- B -" RESET << std::endl;
	}
	catch (std::exception &e) { std::cout << REDD << "NOT B" << std::endl; }
	
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << LIME "- C -" RESET << std::endl;
	}
	catch (std::exception &e) { std::cout << REDD << "NOT C" << std::endl; }
}

int	main(void)
{
	std::cout << CLRALL;

	srand(static_cast<unsigned int>(time(0))); // Initialise le générateur de nombres aléatoires.

	Base* instances[INSTANCES];
	
	// Génère INSTANCES random de A, B, ou C.
	for (int i = 0; i < INSTANCES; ++i)
		instances[i] = generate();

	// Identifie le type de chaque instance via un pointeur.
	std::cout << GRY1 "Identify pointer:" RESET<< std::endl;
	for (int i = 0; i < INSTANCES; ++i)
		identify(instances[i]);
	std::cout << std::endl;

	// Identifie le type de chaque instance via une référence.
	std::cout << GRY1 "Identifiy reference:" RESET << std::endl;
	for (int i = 0; i < INSTANCES; ++i)
	{
		identify(*instances[i]);
		std::cout << std::endl;
	}

	for (int i = 0; i < INSTANCES; ++i)
		delete instances[i];
	return (0);
}

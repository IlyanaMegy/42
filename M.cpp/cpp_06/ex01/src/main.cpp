/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:24:36 by ilymegy           #+#    #+#             */
/*   Updated: 2024/11/26 14:24:40 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/style.hpp"
#include "../inc/Serializer.hpp"

inline void	printDebug(const std::string &mess)
{
	std::cout << GRY1 "*************************************" << std::endl;
	std::cout << mess << std::endl;
	std::cout << "*************************************" RESET << std::endl;
}

int	main(void)
{
	Data	A;
	Data	B;
	Data	*C;

	uintptr_t result;

	std::cout << CLRALL;

	printDebug("INIT DATA A & DATA B & DATA C");
	std::cout << CYAN "A et B ont des valeurs distinctes" << std::endl;
	std::cout << "C pointe vers B" RESET << std::endl;
	A.number = 42;
	A.name = "Deux fois vingt-et-un";
	B.number = 1312;
	B.name = "ACAB";
	C = &B;
	std::cout << std::endl;

	printDebug("PRINT VALUES OF A");
	std::cout << GRY2 "A - number :\t" GOLD << A.number << RESET << std::endl;
	std::cout << GRY2 "A - name :\t" GOLD << A.name << RESET << std::endl;
	std::cout << GRY2 "A - addr :\t" GOLD << &A << RESET << std::endl;
	std::cout << std::endl;

	printDebug("PRINT VALUES OF B");
	std::cout << GRY2 "B - number :\t" MAGN << B.number << RESET << std::endl;
	std::cout << GRY2 "B - name :\t" MAGN << B.name << RESET << std::endl;
	std::cout << GRY2 "B - addr :\t" MAGN << &B << RESET << std::endl;
	std::cout << std::endl;

	printDebug("PRINT VALUES OF C");
	std::cout << GRY2 "C - number :\t" LIME << C->number << RESET << std::endl;
	std::cout << GRY2 "C - name :\t" LIME << C->name << RESET << std::endl;
	std::cout << GRY2 "C - addr :\t" LIME << C << RESET << std::endl;
	std::cout << std::endl;

	std::cout << CYAN "///// SERIALIZE A /////" RESET << std::endl;
	result = Serializer::serialize(&A);
	std::cout << GRY2 "Result :\t" CYAN << result << RESET << std::endl;
	std::cout << std::endl;

	// printDebug("DESERIALIZE C");
	std::cout << CYAN "//// DESERIALIZE C ////" RESET << std::endl;
	C = Serializer::deserialize(result);
	std::cout << GRY2 "Result :\t" CYAN << result << RESET << std::endl;
	std::cout << std::endl;
	
	printDebug("PRINT VALUES OF A");
	std::cout << GRY2 "A - number :\t" GOLD << A.number << RESET << std::endl;
	std::cout << GRY2 "A - name :\t" GOLD << A.name << RESET << std::endl;
	std::cout << GRY2 "A - addr :\t" GOLD << &A << RESET << std::endl;
	std::cout << std::endl;

	printDebug("PRINT VALUES OF B");
	std::cout << GRY2 "B - number :\t" MAGN << B.number << RESET << std::endl;
	std::cout << GRY2 "B - name :\t" MAGN << B.name << RESET << std::endl;
	std::cout << GRY2 "B - addr :\t" MAGN << &B << RESET << std::endl;
	std::cout << std::endl;

	printDebug("PRINT VALUES OF C");
	std::cout << GRY2 "C - number :\t" LIME << C->number << RESET << std::endl;
	std::cout << GRY2 "C - name :\t" LIME << C->name << RESET << std::endl;
	std::cout << GRY2 "C - addr :\t" LIME << C << RESET << std::endl;
	std::cout << std::endl;

	if (&A == C)
		std::cout << CYAN "✅ Maintenant C pointe vers A ✅" RESET << std::endl;
	else
		std::cout << REDD "❌ C DEVRAIT pointer vers A ❌" RESET << std::endl;
	std::cout << GRY1 "*************************************" RESET << std::endl << std::endl;

	return (0);
}

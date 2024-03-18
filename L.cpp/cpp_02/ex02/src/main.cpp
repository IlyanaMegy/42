/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:43:38 by ilymegy           #+#    #+#             */
/*   Updated: 2024/03/13 18:43:39 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

int	main(void)
{
	Fixed	a;
	Fixed	b;

	Fixed &c = a;
	a = Fixed(4.2f);
	b = Fixed(2.4f);
	std::cout << "a = " << a << " b = " << b << " c = " << c << std::endl;
	std::cout << std::endl;
	std::cout << a++ << " becomes " << a << std::endl;
	std::cout << "reset to " << --a << std::endl;
	std::cout << std::endl;
	std::cout << b++ << " becomes " << b << std::endl;
	std::cout << "reset to " << --b << std::endl;
	std::cout << std::endl;
	std::cout << "a + b = " << a << " + " << b << " = " << a + b << std::endl;
	std::cout << std::endl;
	std::cout << "a - a = " << a << " - " << a << " = " << a - a << std::endl;
	std::cout << std::endl;
	std::cout << "b / b = " << b << " / " << b << " = " << b / b << std::endl;
	std::cout << std::endl;
	std::cout << "b * 0 = " << b << " * " << 0 << " = " << b * 0 << std::endl;
	std::cout << std::endl;
	if (b < a)
		std::cout << "b < a" << std::endl;
	std::cout << std::endl;
	if (a > b)
		std::cout << "a > b" << std::endl;
	std::cout << std::endl;
	if (a == c)
		std::cout << "a == c" << std::endl;
	if (a >= c)
		std::cout << "a == c" << std::endl;
	if (a <= c)
		std::cout << "a == c" << std::endl;
	std::cout << std::endl;

	// Fixed	a;
	// Fixed const b(Fixed(5.05f) * Fixed(2));
	// std::cout << a << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;
	// std::cout << b << std::endl;
	// std::cout << Fixed::max(a, b) << std::endl;
	return (0);
}

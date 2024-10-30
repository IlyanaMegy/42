/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:34:17 by ilymegy           #+#    #+#             */
/*   Updated: 2024/10/30 18:34:18 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){};
ScalarConverter::ScalarConverter(ScalarConverter const &src){(void)src;}
ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src){(void)src; return (*this);}
ScalarConverter::~ScalarConverter(){};

void ScalarConverter::convert(const std::string &input)
{
	if (isChar(input))
		toChar(input);
	else if (isInt(input))
		toInt(input);
	else if	(isFloat(input))
		toFloat(input);
	else if (isDouble(input))
		toDouble(input);
	// else if
	else
		std::cout << RUBY "Invalid input. Enter a char, int, float or double value." RESET << std::endl;	
}
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
	else if (isInf(input))
		handleInf(input);
	else
		std::cout << RUBY "Invalid input. Enter a char, int, float or double value." RESET << std::endl;	
}

//	------------------------------------	CHAR	----------------------------------------------------
bool ScalarConverter::isChar(const std::string &input)
{
	if (input.size() == 1)
		return true;
	if (input.size() == 3 && input[0] == '\'' && input[2] == '\'')
		return true;
	return false;
}

void ScalarConverter::toChar(const std::string &input)
{
	char c = input[0];
	int		i = static_cast<int>(c);
	float	f = static_cast<float>(c);
	double	d = static_cast<double>(c);

	if (input.size() == 3 && input[0] == '\'' && input[2] == '\'')
		c = input[1];
	if (isprint(c))
		std::cout << GOLD "char:   \t'" << c << "'" RESET << std::endl;
	else
		std::cout << RED1 "char:   \t" << "non displayable" RESET << std::endl;
	std::cout << LIME "int:    \t" << i << RESET << std::endl;
	std::cout << CYAN "float:  \t" << std::fixed << std::setprecision(1) << f  << "f" RESET << std::endl;
	std::cout << ORNG "double: \t" << d << RESET << std::endl;
}

//	------------------------------------	INT		-------------------------------------------------------
bool ScalarConverter::isInt(const std::string &input)
{
	size_t start = 0;

	if (input.empty()) return false;
	while (start < input.size() && std::isspace(start)) start++;
	
	if (start == input.size()) return false;
	if (input[start] == '+' || input[start] == '-') start++;
	if (start == input.size() || !std::isdigit(input[start])) return false;

	for (size_t i = start; i < input.size(); i++)
		if (!std::isdigit(input[i]))
			return false;
	try
	{
		char *p_input;
		long long int res = strtoll(input.c_str(),&p_input, 10);
		if (res < INT_MIN || res > INT_MAX)
			return false;
	}
	catch (const std::invalid_argument &e) { return (false); }
	catch (const std::out_of_range &e) { return (false); }

	return (true);
}

void ScalarConverter::toInt(const std::string &input)
{
	char c;
	int i = atoi(input.c_str());
	float f;
	double d;

	if (i >= std::numeric_limits<char>::min() && i <= std::numeric_limits<char>::max())
	{
		c = static_cast<char>(i);
		if (isprint(c))
			std::cout << GOLD "char:   \t'" << c << "'" RESET << std::endl;
		else
			std::cout << RED1 "char:   \t" << "non displayable" RESET << std::endl;
	}
	else
		std::cout << REDD "char:   \t" << "impossible" RESET << std::endl;
	std::cout << LIME "int:    \t" << i << RESET << std::endl;
	f = static_cast<float>(i);
	std::cout << CYAN "float:  \t" << std::fixed << std::setprecision(1) << f << "f" RESET << std::endl;
	d = static_cast<double>(i);
	std::cout << ORNG "double: \t" << d << RESET << std::endl;
}

//	------------------------------------	FLOAT	----------------------------------------------------
bool ScalarConverter::isFloat(const std::string &input)
{
	if (input.empty()) return false;

	bool digitBefore = false;
	bool foundDecimal = false;
	bool digitAfter = false;
	size_t i = 0;

	while (i < input.size() && std::isspace(input[i])) i++;
	if (i == input.size()) return false;
	if (input[i] == '+' || input[i] == '-') i++;
	if (i == input.size()) return false;
	for (; i < input.size() && std::isdigit(input[i]); i++)
		digitBefore = true;
	if (i < input.size() && input[i] == '.')
	{
		foundDecimal = true;
		i++;
	}
	for (; i < input.size() && std::isdigit(input[i]); i++)
		digitAfter = true;
	if (i == input.size() - 1 && (input[i] == 'f' || input[i] == 'F') && (digitBefore || digitAfter) && foundDecimal)
		return true;
	return false;
}

void ScalarConverter::toFloat(const std::string &input)
{
	char c;
	int i;
	float f = strtof(input.c_str(), 0);
	double d;

	if (f >= std::numeric_limits<char>::min() && f <= std::numeric_limits<char>::max())
	{
		c = static_cast<char>(f);
		if (isprint(c))
			std::cout << GOLD "char:   \t'" << c << "'" RESET << std::endl;
		else
			std::cout << RED1 "char:   \t" << "non displayable" RESET << std::endl;
	}
	else
		std::cout << REDD "char:   \t" << "impossible" RESET << std::endl;
	if (f >= std::numeric_limits<int>::min() && f <= std::numeric_limits<int>::max())
	{
		i = static_cast<int>(f);
		std::cout << LIME "int:    \t" << i << RESET << std::endl;
	}
	else
		std::cout << REDD "int:    \t" << "impossible" RESET << std::endl;
	std::cout << CYAN "float:  \t" << std::fixed << std::setprecision(1) << f << "f" RESET << std::endl;
	d = static_cast<double>(f);
	std::cout << ORNG "double: \t" << d << RESET << std::endl;
}

//	------------------------------------	DOUBLE	----------------------------------------------------
bool	ScalarConverter::isDouble(const std::string &input)
{
	if (input.empty()) return false;

	bool digitBefore = false;
	bool foundDecimal = false;
	bool digitAfter = false;
	bool foundExp = false;
	bool digitAfterExp = false;
	size_t i = 0;

	while (i < input.size() && std::isspace(input[i])) i++;
	if (i == input.size()) return false;
	if (input[i] == '+' || input[i] == '-') i++;
	if (i == input.size()) return false;
	for (; i < input.size() && std::isdigit(input[i]); i++)
		digitBefore = true;
	if (i < input.size() && input[i] == '.')
	{
		foundDecimal = true;
		i++;
	}
	for (; i < input.size() && std::isdigit(input[i]); i++)
		digitAfter = true;
	if (i < input.size() && (input[i] == 'e' || input[i] == 'E'))
	{
		foundExp = true;
		i++;
		if (i < input.size() && (input[i] == '+' || input[i] == '-')) i++;
		for (; i< input.size() && std::isdigit(input[i]); i++)
			digitAfterExp = true;
	}
	if (i < input.size() && foundDecimal && (digitBefore || digitAfter) && (!foundExp || (foundExp && digitAfterExp)))
		return true;
	return false;
}

void	ScalarConverter::toDouble(const std::string &input)
{
	char c;
	int i;
	float f;
	double d = strtod(input.c_str(), 0);
	// double d = std::stod(input);

	if (d >= std::numeric_limits<char>::min() && d <= std::numeric_limits<char>::max())
	{
		c = static_cast<char>(d);
		if (isprint(c))
			std::cout << GOLD "char:   \t'" << c << "'" RESET << std::endl;
		else
			std::cout << RED1 "char:   \t" << "non displayable" RESET << std::endl;
	}
	else
		std::cout << REDD "char:   \t" << "impossible" RESET << std::endl;
	if (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max())
	{
		i = static_cast<int>(d);
		std::cout << LIME "int:    \t" << i << RESET << std::endl;
	}
	else
		std::cout << RED1 "int:    \t" << "impossible" RESET << std::endl;
	f = static_cast<float>(d);
	std::cout << CYAN "float:  \t" << std::fixed << std::setprecision(1) << f << "f" RESET << std::endl;
	std::cout << ORNG "double: \t" << d << RESET << std::endl;
}

//	------------------------------------	INFINITY ----------------------------------------------------
bool ScalarConverter::isInf(const std::string &input)
{
	const std::string specials[] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
	for (int i = 0; i < 6; i++)
		if (input == specials[i])
			return true;
	return false;
}

void ScalarConverter::handleInf(const std::string &input)
{
	std::cout << RED1 "char:   \t" << "impossible" RESET << std::endl;
	std::cout << RED1 "int:    \t" << "impossible" RESET << std::endl;
	if (input == "-inff" || input == "+inff" || input == "nanf")
	{
		std::cout << CYAN "float:  \t" << input << RESET << std::endl;
		std::string inputFixed = input.substr(0, input.size() - 1);
		std::cout << ORNG "double: \t" << inputFixed << RESET << std::endl;
	}
	else
	{
		std::cout << CYAN << "float:  \t" << input << "f" RESET << std::endl;
		std::cout << ORNG "double: \t" << input << RESET << std::endl;
	}
}

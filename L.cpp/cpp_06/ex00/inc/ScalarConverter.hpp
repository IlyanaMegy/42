/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:34:07 by ilymegy           #+#    #+#             */
/*   Updated: 2024/10/30 18:34:08 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include "style.hpp"
# include <climits>
# include <iomanip>
# include <iostream>
# include <limits>
# include <string>

class ScalarConverter
{
  public:
	static void convert(const std::string &input);

  private:
	ScalarConverter();
	ScalarConverter(ScalarConverter const &src);
	ScalarConverter &operator=(ScalarConverter const &src);
	~ScalarConverter();

	static bool isChar(const std::string &input);
	static bool isInt(const std::string &input);
	static bool isFloat(const std::string &input);
	static bool isDouble(const std::string &input);
	static bool isInf(const std::string &input);

	static void toChar(const std::string &input);
	static void toInt(const std::string &input);
	static void toFloat(const std::string &input);
	static void toDouble(const std::string &input);
	static void handleInf(const std::string &input);
};

#endif
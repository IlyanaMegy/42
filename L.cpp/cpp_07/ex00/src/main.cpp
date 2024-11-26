/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:33:12 by ilymegy           #+#    #+#             */
/*   Updated: 2024/11/26 15:33:14 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/whatever.hpp"
#include "../inc/style.hpp"
#include <string>
#include <iostream>
#include <iomanip>

int	main(void)
{
	std::cout << CLRALL;

	std::cout << BLUE "## WITH INTEGER ##" RESET << std::endl;
	int	int_a = 42;
	int	int_b = 69;
	std::cout << GRY1 "a  : " CYAN << int_a << RESET << std::endl;
	std::cout << GRY1 "b  : " CYAN << int_b << RESET << std::endl;
	swap(int_a, int_b);
	std::cout << GRY1 "// after swap()" CYAN << RESET << std::endl;
	std::cout << GRY1 "a  : " CYAN << int_a << RESET << std::endl;
	std::cout << GRY1 "b  : " CYAN << int_b << RESET << std::endl;
	std::cout << GRY1 "min: " CYAN << min(int_a, int_b) << RESET << std::endl;
	std::cout << GRY1 "max: " CYAN << max(int_a, int_b) << RESET << std::endl;

	std::cout << std::endl;
	std::cout << BLUE "## WITH FLOATS ##" RESET << std::endl;
	float	fl_a = 42.24f;
	float	fl_b = 69.96f;
	std::cout << GRY1 "a  : " GOLD << fl_a << RESET << std::endl;
	std::cout << GRY1 "b  : " GOLD << fl_b << RESET << std::endl;
	swap(fl_a, fl_b);
	std::cout << GRY1 "// after swap()" GOLD << RESET << std::endl;
	std::cout << GRY1 "a  : " GOLD << fl_a << RESET << std::endl;
	std::cout << GRY1 "b  : " GOLD << fl_b << RESET << std::endl;
	std::cout << GRY1 "min: " GOLD << min(fl_a, fl_b) << RESET << std::endl;
	std::cout << GRY1 "max: " GOLD << max(fl_a, fl_b) << RESET << std::endl;


	std::cout << std::endl;
	std::cout << BLUE "## WITH DOUBLES ##" RESET << std::endl;
	double	db_a = 42.42;
	double	db_b = 69.69;
	std::cout << GRY1 "a  : " SALM << db_a << RESET << std::endl;
	std::cout << GRY1 "b  : " SALM << db_b << RESET << std::endl;
	swap(db_a, db_b);
	std::cout << GRY1 "// after swap()" SALM << RESET << std::endl;
	std::cout << GRY1 "a  : " SALM << db_a << RESET << std::endl;
	std::cout << GRY1 "b  : " SALM << db_b << RESET << std::endl;
	std::cout << GRY1 "min: " SALM << min(db_a, db_b) << RESET << std::endl;
	std::cout << GRY1 "max: " SALM << max(db_a, db_b) << RESET << std::endl;


	std::cout << std::endl;
	std::cout << BLUE "## WITH CHARS ##" RESET << std::endl;
	char	c_a = 'A';
	char	c_b = 'Z';
	std::cout << GRY1 "a  : " REDD << c_a << RESET << std::endl;
	std::cout << GRY1 "b  : " REDD << c_b << RESET << std::endl;
	swap(c_a, c_b);
	std::cout << GRY1 "// after swap()" REDD << RESET << std::endl;
	std::cout << GRY1 "a  : " REDD << c_a << RESET << std::endl;
	std::cout << GRY1 "b  : " REDD << c_b << RESET << std::endl;
	std::cout << GRY1 "min: " REDD << min(c_a, c_b) << RESET << std::endl;
	std::cout << GRY1 "max: " REDD << max(c_a, c_b) << RESET << std::endl;

	std::cout << std::endl;
	std::cout << BLUE "## WITH STRINGS ##" RESET << std::endl;
	std::string	stra = "Hello World 2";
	std::string	strb = "Hello World 1";
	std::cout << GRY1 "a  : " PURP << stra << RESET << std::endl;
	std::cout << GRY1 "b  : " PURP << strb << RESET << std::endl;
	swap(stra, strb);
	std::cout << GRY1 "// after swap()" PURP << RESET << std::endl;
	std::cout << GRY1 "a  : " PURP << stra << RESET << std::endl;
	std::cout << GRY1 "b  : " PURP << strb << RESET << std::endl;
	std::cout << GRY1 "min: " PURP << min(stra, strb) << RESET << std::endl;
	std::cout << GRY1 "max: " PURP << max(stra, strb) << RESET << std::endl;

	std::cout << std::endl;
	std::cout << BLUE "## WITH BOOLS ##" RESET << std::endl;
	bool	ba = true;
	bool	bb = false;
	std::cout << GRY1 "a  : " LIME << ba << RESET << std::endl;
	std::cout << GRY1 "b  : " LIME << bb << RESET << std::endl;
	swap(ba, bb);
	std::cout << GRY1 "// after swap()" LIME << RESET << std::endl;
	std::cout << GRY1 "a  : " LIME << ba << RESET << std::endl;
	std::cout << GRY1 "b  : " LIME << bb << RESET << std::endl;
	std::cout << GRY1 "min: " LIME << min(ba, bb) << RESET << std::endl;
	std::cout << GRY1 "max: " LIME << max(ba, bb) << RESET << std::endl;

	return (0);
}

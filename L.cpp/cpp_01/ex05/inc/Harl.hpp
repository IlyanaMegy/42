/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:14:11 by ilymegy           #+#    #+#             */
/*   Updated: 2024/03/12 16:14:12 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
# include <iomanip>
# include <iostream>
# include <string>
# include <map>

class Harl
{
  private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
	using DicoPtr = void (Harl::*)();
	DicoPtr functions[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::map<std::string, int> levelDico = {
		{"debug", 0},
		{"info", 1},
		{"warning", 2},
		{"error", 3}};

  public:
	Harl(void);
	~Harl(void);
	void complain(std::string level);
};

#endif

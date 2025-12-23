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
# include <map>
# include <string>

class Harl
{
  private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

  public:
	Harl();
	~Harl(void);
	void complain(std::string level);
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GodMode.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:12:44 by ilymegy           #+#    #+#             */
/*   Updated: 2024/09/24 14:12:46 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GODMODE_HPP
# define GODMODE_HPP
# include "Bureaucrat.hpp"

class	Bureaucrat;

class GodMode
{
  private:
	// Bureaucrat _humans[200];
	int _index;
	bool _full;

  public:
	GodMode(void);
	~GodMode(void);
	void greetings(const std::string greetings);
	// void new_human(void);
	// void show_humans(void);
	void show_cmds(void);
	// void kill_human(void);
};
#endif

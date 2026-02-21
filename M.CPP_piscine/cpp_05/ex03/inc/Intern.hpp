/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 21:00:25 by ilymegy           #+#    #+#             */
/*   Updated: 2024/10/17 21:00:27 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class	AForm;
class	PresidentialPardonForm;
class	RobotomyRequestForm;
class	ShrubberyCreationForm;
class Intern
{
  public:
	Intern();
	Intern(Intern const &src);
	Intern &operator=(Intern const &src);
	~Intern();

	AForm *makeForm(const std::string form, const std::string target);
};

#endif

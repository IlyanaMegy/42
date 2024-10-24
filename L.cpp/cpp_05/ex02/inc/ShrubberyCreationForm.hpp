/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:34:12 by ilymegy           #+#    #+#             */
/*   Updated: 2024/10/07 14:34:14 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "Bureaucrat.hpp"
# include <fstream>
# include <typeinfo>

class	Bureaucrat; 
class	AForm;
class ShrubberyCreationForm : public AForm
{
  private:
	std::string _target;

  protected:
	void executeAction() const;

  public:
	// Constructors
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm const &src);

	// Overloaded Operators
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &src);

	// Deconstructor
	~ShrubberyCreationForm();

	// Getter
	std::string getTarget() const;
};

// ostream Overload
std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm *a);
#endif

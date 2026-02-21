/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:32:59 by ilymegy           #+#    #+#             */
/*   Updated: 2024/10/07 14:33:04 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "AForm.hpp"
# include <cstdio>
# include <cstdlib>
# include <iomanip>
# include <iostream>

class	Bureaucrat;
class	AForm;
class PresidentialPardonForm : public AForm
{
  private:
	std::string _target;

  protected:
	void executeAction() const;

  public:
	// Constructors
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm const &src);

	// Overloaded Operators
	PresidentialPardonForm &operator=(PresidentialPardonForm const &src);

	// Deconstructor
	virtual ~PresidentialPardonForm();

	// Getter
	std::string getTarget() const;
};

// ostream Overload
std::ostream &operator<<(std::ostream &o, PresidentialPardonForm *a);
#endif

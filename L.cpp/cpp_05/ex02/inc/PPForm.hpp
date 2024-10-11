/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PPForm.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:32:59 by ilymegy           #+#    #+#             */
/*   Updated: 2024/10/07 14:33:04 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PPFORM_HPP
# define PPFORM_HPP
# include "AForm.hpp"
# include <cstdio>
# include <cstdlib>
# include <iomanip>
# include <iostream>

class	Bureaucrat;
class	AForm;
class PPForm: public AForm
{
  private:
	std::string _target;

  protected:
	void executeAction() const;

  public:
	// Constructors
	PPForm();
	PPForm(std::string target);
	PPForm(PPForm const &src);

	// Overloaded Operators
	PPForm &operator=(PPForm const &assign);

	// Deconstructor
	virtual ~PPForm();

	// Getter
	std::string getTarget(void) const;
};

// ostream Overload
std::ostream &operator<<(std::ostream &o, PPForm *a);
#endif

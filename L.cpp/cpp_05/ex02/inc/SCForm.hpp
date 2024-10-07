/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SCForm.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:34:12 by ilymegy           #+#    #+#             */
/*   Updated: 2024/10/07 14:34:14 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCFORM_HPP
# define SCFORM_HPP

# include "Bureaucrat.hpp"

class	Bureaucrat;
class	AForm;
class SCForm : public AForm
{
  private:
	const std::string _target;
	SCForm(void);

  public:
	// Constructors
	SCForm(std::string target);
	SCForm(SCForm &copy);

	// Overloaded Operators
	SCForm &operator=(SCForm const &assign);

	// Deconstructor
	~SCForm(void);

	// Public Methods
	void execute(Bureaucrat const &executor) const;

	// Getter
	std::string getTarget(void) const;
};

// ostream Overload
std::ostream &operator<<(std::ostream &o, SCForm *a);
#endif

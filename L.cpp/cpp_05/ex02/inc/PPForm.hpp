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

# include "Bureaucrat.hpp"

class	Bureaucrat;
class	AForm;
class PPForm : public AForm
{
  private:
	const std::string _target;
	PPForm(void);

  public:
	// Constructors
	PPForm(std::string target);
	PPForm(PPForm &copy);

	// Deconstructor
	~PPForm(void);

	// Overloaded Operators
	PPForm &operator=(PPForm const &assign);

	// Public Methods
	void execute(Bureaucrat const &executor) const;

	// Getter
	std::string getTarget(void) const;
};

// ostream Overload
std::ostream &operator<<(std::ostream &o, PPForm *a);
#endif

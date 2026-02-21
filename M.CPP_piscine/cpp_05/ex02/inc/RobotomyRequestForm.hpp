/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:33:39 by ilymegy           #+#    #+#             */
/*   Updated: 2024/10/07 14:33:40 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "Bureaucrat.hpp"

class	Bureaucrat;
class	AForm;
class RobotomyRequestForm : public AForm
{
  private:
	std::string _target;

  protected:
	void executeAction() const;

  public:
	// Constructors
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const &src);

	// Overloaded Operators
	RobotomyRequestForm &operator=(RobotomyRequestForm const &src);

	// Deconstructor
	~RobotomyRequestForm();

	// Getter
	std::string getTarget() const;
};

// ostream Overload
std::ostream &operator<<(std::ostream &o, RobotomyRequestForm *a);
#endif

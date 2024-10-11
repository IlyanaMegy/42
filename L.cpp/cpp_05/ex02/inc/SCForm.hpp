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
# include <fstream>
# include <typeinfo>

class	Bureaucrat;
class	AForm;
class SCForm : public AForm
{
  private:
	const std::string _target;

  protected:
	void executeAction() const;

  public:
	// Constructors
	SCForm();
	SCForm(const std::string target);
	SCForm(SCForm const &src);

	// Overloaded Operators
	SCForm &operator=(SCForm const &src);

	// Deconstructor
	~SCForm();

	// Getter
	std::string getTarget() const;
};

// ostream Overload
std::ostream &operator<<(std::ostream &o, SCForm *a);
#endif

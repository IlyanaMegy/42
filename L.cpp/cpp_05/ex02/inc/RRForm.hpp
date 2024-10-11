/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RRForm.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:33:39 by ilymegy           #+#    #+#             */
/*   Updated: 2024/10/07 14:33:40 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RRFORM_HPP
# define RRFORM_HPP
# include "Bureaucrat.hpp"

class	Bureaucrat;
class	AForm;
class RRForm : public AForm
{
  private:
	const std::string _target;

  protected:
	void executeAction() const;

  public:
	// Constructors
	RRForm();
	RRForm(std::string target);
	RRForm(RRForm const &src);

	// Overloaded Operators
	RRForm &operator=(RRForm const &src);

	// Deconstructor
	~RRForm();

	// Getter
	std::string getTarget(void) const;
};

// ostream Overload
std::ostream &operator<<(std::ostream &o, RRForm *a);
#endif

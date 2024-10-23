/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RRForm.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 21:00:06 by ilymegy           #+#    #+#             */
/*   Updated: 2024/10/17 21:00:08 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RRFORM_HPP
# define RRFORM_HPP
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class	Bureaucrat;
class	AForm;
class RRForm : public AForm
{
  private:
	std::string _target;

  protected:
	void executeAction() const;

  public:
	RRForm();
	RRForm(RRForm const &src);
	RRForm(std::string target);
	RRForm &operator=(RRForm const &src);
	~RRForm();

	std::string getTarget() const;
};

std::ostream &operator<<(std::ostream &o, RRForm *a);
#endif

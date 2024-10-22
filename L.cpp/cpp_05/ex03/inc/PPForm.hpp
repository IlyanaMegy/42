/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PPForm.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 20:59:56 by ilymegy           #+#    #+#             */
/*   Updated: 2024/10/17 20:59:57 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PPFORM_HPP
# define PPFORM_HPP

# include "AForm.hpp"

class	Bureaucrat;
class	AForm;
class PPForm : public AForm
{
  private:
	std::string _target;

  protected:
	void executeAction() const;

  public:
	PPForm();
	PPForm(PPForm const &src);
	PPForm(std::string target);
	PPForm &operator=(PPForm const &src);
	virtual ~PPForm();

	std::string getTarget() const;
};

std::ostream &operator<<(std::ostream &o, PPForm *a);
#endif

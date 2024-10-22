/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SCForm.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 20:59:47 by ilymegy           #+#    #+#             */
/*   Updated: 2024/10/17 20:59:49 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCFORM_HPP
# define SCFORM_HPP

# include "AForm.hpp"

class	Bureaucrat;
class	AForm;
class SCForm : public AForm
{
  private:
	std::string _target;

  protected:
	void executeAction() const;

  public:
	SCForm();
	SCForm(SCForm const &src);
	SCForm(std::string target);
	SCForm &operator=(SCForm const &src);
	~SCForm();

	std::string getTarget() const;
};

std::ostream &operator<<(std::ostream &o, SCForm *a);
#endif

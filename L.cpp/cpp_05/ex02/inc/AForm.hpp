/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:41:45 by ilymegy           #+#    #+#             */
/*   Updated: 2024/09/23 15:41:47 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP
# include "Bureaucrat.hpp"

class AForm
{
  private:
	const std::string _name;
	bool _signed;
	const int _sign_grade;
	const int _exec_grade;

  public:
	// Constructors
	AForm(void);
	AForm(AForm const &copy);
	AForm(int sign_grade, int exec_grade);
	AForm(const std::string name);
	AForm(const std::string name, int sign_grade, int exec_grade);

	// Overloaded Operators
	AForm &operator=(AForm const &assign);

	// Deconstructor
	virtual ~AForm(void);
};

#endif

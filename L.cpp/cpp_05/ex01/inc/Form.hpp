/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:47:17 by ilymegy           #+#    #+#             */
/*   Updated: 2024/09/17 16:47:18 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
  private:
	const std::string _name;
	bool _signed;
	const int _sign_grade;
	const int _exec_grade;

  public:
	// Constructors
	Form(void);
	Form(Form const &copy);
	Form(int sign_grade, int exce_grade);
	Form(const std::string name);
	Form(const std::string name, int sign_grade, int exec_grade);

	// Overloeaded Operators
	Form &operator=(Form const &assign);

	// Deconsructor
	~Form(void);

	// Public Methods
	void doSign(Bureaucrat &human);

	// Getters
	const std::string getName(void) const;
	const std::string getSigned(void) const;
	bool getSignedBool(void) const;
	int getSignGrade(void) const;
	int getExecGrade(void) const;

	// Execeptions
	class GradeTooLowException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};

	class GradeTooHighException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};
};

// ostream Overload
std::ostream &operator<<(std::ostream &o, Form *a);
#endif

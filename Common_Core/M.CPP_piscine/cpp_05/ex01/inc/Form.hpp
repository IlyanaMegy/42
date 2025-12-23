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

class	Bureaucrat;
class Form
{
  private:
	const std::string _name;
	bool _isSigned;
	const size_t _sign_grade;
	const size_t _exec_grade;

  public:
	// Constructors
	Form();
	Form(Form const &src);
	Form(int sign_grade, int exec_grade);
	Form(const std::string name);
	Form(const std::string name, int sign_grade, int exec_grade);

	// Overloaded Operators
	Form &operator=(Form const &src);

	// Deconstructor
	~Form();

	// Public Methods
	void beSigned(Bureaucrat &human);

	// Getters
	const std::string getName() const;
	size_t setGrade(int grade);
	const std::string getIsSigned() const;
	bool getIsSignedBool() const;
	size_t getSignGrade() const;
	size_t getExecGrade() const;

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

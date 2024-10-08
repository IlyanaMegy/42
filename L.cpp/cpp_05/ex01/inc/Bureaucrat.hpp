/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:47:08 by ilymegy           #+#    #+#             */
/*   Updated: 2024/09/17 16:47:09 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <cstdio>
# include <cstdlib>
# include <iomanip>
# include <iostream>
# include "Form.hpp"

# define BLACK "\033[30m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define ORANGE "\033[38;5;208m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"
# define UNDERLINE "\033[4m"
# define RESET "\033[0m"
# define FALSE_EMOJI "❌"
# define TRUE_EMOJI "✅"

class Form;
class Bureaucrat
{
  private:
	const std::string _name;
	size_t _grade;
	size_t setGrade(int grade);

  public:
	// Constructors
	Bureaucrat();
	Bureaucrat(Bureaucrat const &src);
	Bureaucrat(int grade);
	Bureaucrat(const std::string name);
	Bureaucrat(const std::string name, int grade);

	// Overloaded Operators
	Bureaucrat &operator=(Bureaucrat const &src);

	// Deconstructor
	~Bureaucrat();

	// Public Methods
	void incrementGrade();
	void decrementGrade();
	void signForm(Form &form);

	// Getters
	const std::string getName() const;
	size_t getGrade() const;

	// Exceptions
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

	class InvalidNameException : public std::exception
	{
		public:
		const char *what() const throw();
	};
};

// ostream Overload
std::ostream &operator<<(std::ostream &o, Bureaucrat const *a);
#endif

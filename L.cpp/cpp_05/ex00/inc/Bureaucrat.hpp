/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:49:59 by ilymegy           #+#    #+#             */
/*   Updated: 2024/09/17 13:50:00 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <cstdio>
# include <cstdlib>
# include <iomanip>
# include <iostream>

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

class Bureaucrat
{
  private:
	const std::string _name;
	size_t _grade;
	void setGrade(int grade);

  public:
	// Constructors
	Bureaucrat(void);
	Bureaucrat(Bureaucrat const &copy);
	Bureaucrat(int grade);
	Bureaucrat(const std::string name);
	Bureaucrat(const std::string name, int grade);

	// Overloaded Operators
	Bureaucrat &operator=(Bureaucrat const &assign);

	// Deconstructors
	~Bureaucrat(void);

	// Public Methods
	void incrementGrade(void);
	void decrementGrade(void);

	// Getter
	const std::string getName(void) const;
	size_t getGrade(void) const;

	//Exceptions
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
std::ostream &operator<<(std::ostream &o, Bureaucrat const &a);
#endif

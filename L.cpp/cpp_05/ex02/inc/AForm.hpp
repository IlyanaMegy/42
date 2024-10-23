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

class	Bureaucrat;
class AForm
{
  private:
	const std::string _name;
	bool _isSigned;
	const size_t _sign_grade;
	const size_t _exec_grade;

  protected:
	/* Méthode virtuelle pure pour exécuter l'action du formulaire */
	virtual void executeAction() const = 0;

  public:
	// Constructors
	AForm();
	AForm(AForm const &src);
	AForm(int sign_grade, int exec_grade);
	AForm(const std::string name);
	AForm(const std::string name, int sign_grade, int exec_grade);

	// Overloaded Operators
	AForm &operator=(AForm const &src);

	// Deconstructor
	virtual ~AForm();

	// Public Methods
	void beSigned(Bureaucrat &human);
	void execute(Bureaucrat const &executor) const;

	// Getters
	const std::string getName(void) const;
	size_t setGrade(int grade);
	const std::string getIsSigned(void) const;
	bool getIsSignedBool() const;
	size_t getSignGrade() const;
	size_t getExecGrade() const;

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

	class FormNotSignedException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};
};

// ostream Overload
std::ostream &operator<<(std::ostream &o, AForm *a);
#endif

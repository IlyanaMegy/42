/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:39:14 by ilymegy           #+#    #+#             */
/*   Updated: 2024/09/23 15:39:15 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int main(void)
{
	{
		std::cout << YELLOW << std::endl << "-------------------------------------------------------* Test 1\n// Expecting too high and too low grades errors during creation" << RESET << std::endl;
		try
		{
			Bureaucrat Sleeper1("A", 1500);
		}
		catch(const std::exception &e)
		{
			std::cerr << "Exception caught: " << RED << e.what() << RESET << std::endl;
		}

		try
		{
			Bureaucrat Sleeper2("B", -10);
		}
		catch(const std::exception &e)
		{
			std::cerr << "Exception caught: " << RED << e.what() << RESET << std::endl;
		}
	}

	std::cout << YELLOW << std::endl << "-------------------------------------------------------* Test 2\n// Increasing grade" << RESET << std::endl;
	{
		Bureaucrat bob("Bob", 2);
		std::cout << &bob;
		try
		{
			bob.incrementGrade();
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception caught: " << RED << e.what() << RESET << std::endl;
		}
		std::cout << &bob;
		
		try
		{
			bob.incrementGrade();
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception caught: " << RED << e.what() << RESET << std::endl;
		}
		std::cout << &bob;
	}

	std::cout << YELLOW << std::endl << "-------------------------------------------------------* Test 3\n// Decreasing grade" << RESET << std::endl;
	{
		Bureaucrat tim("Tim", 149);
		std::cout << &tim;
		try
		{
			tim.decrementGrade();
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception caught: " << RED << e.what() << RESET << std::endl;
		}
		std::cout << &tim;
		
		try
		{
			tim.decrementGrade();
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception caught: " << RED << e.what() << RESET << std::endl;
		}
		std::cout << &tim;
	}

	std::cout << YELLOW << std::endl << "-------------------------------------------------------* Test 4\n// Increasing and Decreasing grade" << RESET << std::endl;
	{
		Bureaucrat *a = new Bureaucrat(10);
		std::cout << a;
		try
		{
			a->decrementGrade();
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception caught: " << RED << e.what() << RESET << std::endl;
		}
		std::cout << a;

		try
		{
			a->incrementGrade();
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception caught: " << RED << e.what() << RESET << std::endl;
		}
		std::cout << a;

		try
		{
			a->incrementGrade();
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception caught: " << RED << e.what() << RESET << std::endl;
		}
		std::cout << a;
		std::cout << std::endl;

		std::cout << RED << "Destroying a" << RESET << std::endl;
		delete a;
	}
	
	std::cout << YELLOW << std::endl << "-------------------------------------------------------* Test 5\n// Too high grade error" << RESET << std::endl;
	{
		Bureaucrat *a = NULL;
		try
		{
			a = new Bureaucrat(0);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception caught: " << RED << e.what() << RESET << std::endl;
		}

		if (a != NULL)
		{
			std::cout << RED << "Destroying a" << RESET << std::endl;
			delete a;
		}
	}

	std::cout << YELLOW << std::endl << "-------------------------------------------------------* Test 6\n// Copying a into b" << RESET << std::endl;
	{
		Bureaucrat *a = new Bureaucrat("Peter", 120);
		std::cout << a;

		a->decrementGrade();
		std::cout << a;
		std::cout << std::endl;

		Bureaucrat *b = new Bureaucrat(*a);

		std::cout << RED << "Destroying a" << RESET << std::endl;
		delete a;

		std::cout << b;
		b->decrementGrade();
		std::cout << b;
		std::cout << std::endl;

		std::cout << RED << "Destroying b" << RESET << std::endl;
		delete b;
	}
	return (0);
}

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
#include "../inc/PPForm.hpp"
#include "../inc/RRForm.hpp"
#include "../inc/SCForm.hpp"

#define ASSERT_TEST(expression, message) \
    if (expression) { std::cout << "\033[32m[TEST PASSED]\033[0m " << message << std::endl; } \
    else { std::cout << "\033[31m[TEST FAILED]\033[0m " << message << std::endl; }


int main(void)
{
	Bureaucrat *original = NULL;
	Bureaucrat *copy = NULL;

	/**
	* TEST CREATION OF BUREAUCRAT WITH VALID GRADE
	*/
	std::cout << CYAN << "TEST CREATION OF BUREAUCRAT WITH VALID GRADE:" << RESET << std::endl;
	try
	{
		original = new Bureaucrat("John Doe", 75);
		std::cout << original;
		ASSERT_TEST(original->getGrade() == 75, "Grade 75.");
		delete original;
		original = NULL;
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
		ASSERT_TEST(false, "Should not throw an exception here.");
	}
/**
	* TEST CREATION OF BUREAUCRAT WITH TOO HIGH GRADE
	*/
	std::cout << CYAN << "\nTEST CREATION OF BUREAUCRAT WITH TOO HIGH GRADE:" << RESET << std::endl;
	try
	{
		original = new Bureaucrat("Jane Doe", 0);
		std::cout << original;
		delete original;
		original = NULL;
		ASSERT_TEST(false, "Should have thrown GradeTooHighException.");
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
		ASSERT_TEST(true, "Correctly threw GradeTooHighException.");
	}
	catch (...)
	{
		ASSERT_TEST(false, "Wrong exception type caught.");
	}

	/**
	* TEST CREATION OF BUREAUCRAT WITH TOO LOW GRADE
	*/
	std::cout << CYAN << "\nTEST CREATION OF BUREAUCRAT WITH TOO LOW GRADE:" << RESET << std::endl;
	try
	{
		original = new Bureaucrat("Jim Doe", 151);
		std::cout << original;
		delete original;
		original = NULL;
		ASSERT_TEST(false, "Should have thrown GradeTooLowException.");
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
		ASSERT_TEST(true, "Correctly threw GradeTooLowException.");
	}
	catch (...)
	{
		ASSERT_TEST(false, "Wrong exception type caught.");
	}

	/**
	* TEST INCREMENTING AND DECREMENTING BUREAUCRAT'S GRADE
	*/
	std::cout << CYAN << "\nTEST INCREMENTING AND DECREMENTING BUREAUCRAT'S GRADE:" << RESET << std::endl;
	try
	{
		original = new Bureaucrat("Julia Doe", 10);
		std::cout << original;
		original->incrementGrade();
		std::cout << BLUE << "\nAfter incrementing bureaucrat :" << RESET << std::endl;
		std::cout << original;
		ASSERT_TEST(original->getGrade() == 9, "Grade incremented to 9.");

		original->decrementGrade();
		std::cout << BLUE << "\nAfter decrementing bureaucrat :" << RESET << std::endl;

		std::cout << original;
		ASSERT_TEST(original->getGrade() == 10, "Grade decremented to 10.");

		delete original;
		original = NULL;
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
		ASSERT_TEST(false, "No exception should be thrown here.");
	}

	/**
	* TEST COPY CONSTRUCTOR
	*/
	std::cout << CYAN << "\nTEST COPY CONSTRUCTOR:" << RESET << std::endl;
	try
	{		
		original = new Bureaucrat("Bureaucrat", 50);
		std::cout << "Original " << original;

		copy = new Bureaucrat(*original);
		std::cout << "Copy " << copy;

		ASSERT_TEST(copy->getName() == original->getName() + "_copy", "Copy have the same name.");
		ASSERT_TEST(copy->getGrade() == original->getGrade(), "Copy have the same grade.");

		copy->incrementGrade();
		std::cout << BLUE << "\nAfter incrementing copy:\n" << RESET;
		std::cout << "Original " << original;
		std::cout << "Copy " << copy;
		ASSERT_TEST(original->getGrade() == 50, "Grade of original unchanged.");
		ASSERT_TEST(copy->getGrade() == 49, "Grade of copy incremented.");

		delete original;
		delete copy;
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
		ASSERT_TEST(false, "No exception should be thrown here.");
	}

	/**
	* TEST ASSIGNMENT OPERATOR
	*/
	std::cout << CYAN << "\nTEST ASSIGNMENT OPERATOR:" << RESET << std::endl;
	try
	{
		original = new Bureaucrat("First", 75);
		copy = new Bureaucrat("Second", 100);
		std::cout <<  BLUE << "Before assignment:" << RESET << std::endl << original << copy << std::endl;

		/**
		* Using assignment operator
		*/
		*copy = *original;
		std::cout << BLUE << "After assignment:" << RESET << std::endl;
		std::cout << original << copy;
		ASSERT_TEST(copy->getName() == "Second", "Name of copy unchanged.");
		ASSERT_TEST(copy->getGrade() == 75, "Grade of copy updated to 75.");

		copy->incrementGrade();
		std::cout << BLUE << "\nAfter incrementing Second Bureaucrat :" << RESET << std::endl;
		std::cout << original << copy;
		ASSERT_TEST(original->getGrade() == 75, "Grade of original unchanged.");
		ASSERT_TEST(copy->getGrade() == 74, "Grade of copy incremented.");

		delete original;
		delete copy;
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
		ASSERT_TEST(false, "No exception should be thrown here.");
	}

    /**
    * TEST BUREAUCRAT CREATION AND FORM EXECUTION
    */
    std::cout << std::endl << CYAN << "TEST BUREAUCRAT CREATION AND FORM EXECUTION:" << RESET << std::endl;
    try
	{
        Bureaucrat bob("Bob", 1);
		SCForm shrub("home");
        RRForm robot("Alice");
        PPForm pardon("Charlie");

        bob.signForm(shrub);
        bob.executeForm(shrub);
        ASSERT_TEST(shrub.getIsSignedBool(), "SCForm signed.");
        ASSERT_TEST(shrub.getIsSignedBool() && shrub.getExecGrade() >= bob.getGrade(), "SCForm executed.");

        bob.signForm(robot);
        bob.executeForm(robot);
        ASSERT_TEST(robot.getIsSignedBool(), "RRForm signed.");
        ASSERT_TEST(robot.getIsSignedBool() && robot.getExecGrade() >= bob.getGrade(), "RRForm executed.");

        bob.signForm(pardon);
        bob.executeForm(pardon);
        ASSERT_TEST(pardon.getIsSignedBool(), "PPForm signed.");
        ASSERT_TEST(pardon.getIsSignedBool() && pardon.getExecGrade() >= bob.getGrade(), "PPForm executed.");
    }
	catch (std::exception &e)
	{
        std::cerr << "Exception: " << e.what() << std::endl;
        ASSERT_TEST(false, "Exception should not be thrown.");
    }

    /**
    * TEST GETTERS IN AForm
    */
    std::cout << CYAN << "\nTEST GETTERS IN AForm:" << RESET << std::endl;
    try
	{
        SCForm shrub("test");
        ASSERT_TEST(shrub.getName() == "ShrubberyCreationForm", "getName() works correctly.");
        ASSERT_TEST(!shrub.getIsSignedBool(), "getIsSigned() works correctly.");
        ASSERT_TEST(shrub.getSignGrade() == 145, "getSignGrade() works correctly.");
        ASSERT_TEST(shrub.getExecGrade() == 137, "getExecGrade() works correctly.");
    }
	catch (std::exception &e)
	{
        ASSERT_TEST(false, "Exception should not be thrown during getters tests.");
    }

    /**
    * TEST AForm CLASS NAME
    */
    std::cout << CYAN << "\nTEST AForm CLASS NAME:" << RESET << std::endl;
    ASSERT_TEST(std::string(typeid(AForm).name()) == "5AForm", "AForm class name is correct.");

    /**
    * TEST SCForm REQUIREMENTS
    */
    std::cout << CYAN << "\nTEST SCForm REQUIREMENTS:" << RESET << std::endl;
    try
	{
        SCForm shrub("home");
        ASSERT_TEST(shrub.getSignGrade() == 145, "SCForm sign grade is 145.");
        ASSERT_TEST(shrub.getExecGrade() == 137, "SCForm execute grade is 137.");
    }
	catch (std::exception &e)
	{
        ASSERT_TEST(false, "SCForm constructor threw an exception.");
    }

    /**
    * TEST SCForm FILE CREATION
    */
    std::cout << CYAN << "\nTEST SCForm:" << RESET << std::endl;
    try
	{
        Bureaucrat bob("Bob", 1);
        SCForm shrub("test_target");
        bob.signForm(shrub);

        /**
		 * Exécuter le formulaire avec executeForm
		*/
        bob.executeForm(shrub);
        std::ifstream infile("test_target_shrubbery");
        ASSERT_TEST(infile.good(), "Shrubbery file created using executeForm.");
        infile.close();
        std::remove("test_target_shrubbery");

        /**
		 * Exécuter le formulaire avec execute
		*/
        shrub.execute(bob);
        infile.open("test_target_shrubbery");
        ASSERT_TEST(infile.good(), "Shrubbery file created using execute.");
        infile.close();
        std::remove("test_target_shrubbery");
    }
	catch (std::exception &e)
	{
        ASSERT_TEST(false, "Exception should not be thrown during Shrubbery creation/execution.");
    }

    /**
    * TEST RRForm REQUIREMENTS
    */
    std::cout << CYAN << "\nTEST RRForm REQUIREMENTS:" << RESET << std::endl;
    try
	{
        RRForm robot("Alice");
        ASSERT_TEST(robot.getSignGrade() == 72, "RRForm sign grade is 72.");
        ASSERT_TEST(robot.getExecGrade() == 45, "RRForm execute grade is 45.");
    }
	catch (std::exception &e)
	{
        ASSERT_TEST(false, "RRForm constructor threw an exception.");
    }

    /**
    * TEST PPForm REQUIREMENTS
    */
    std::cout << CYAN << "\nTEST PPForm REQUIREMENTS:" << RESET << std::endl;
    try
	{
        PPForm pardon("Charlie");
        ASSERT_TEST(pardon.getSignGrade() == 25, "PPForm sign grade is 25.");
        ASSERT_TEST(pardon.getExecGrade() == 5, "PPForm execute grade is 5.");
    }
	catch (std::exception &e)
	{
        ASSERT_TEST(false, "PPForm constructor threw an exception.");
    }
	return 0;
}

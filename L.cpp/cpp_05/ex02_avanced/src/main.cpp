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
#include "../inc/GodMode.hpp"

std::string ran_color(void)
{
	std::string color = "\033[3";
	char n = (char)(rand()%(7) + 50);
	if (n == '8')
		return (ORANGE);
	return (color + n + 'm');
}

int main(void)
{
	GodMode GodMode;
	bool run = true;
	bool godmode = false;
	std::string cmd;

	std::cout << "\t\t   Entering GODMODE ? y/n" << std::endl;
	std::cout << "> ";
	while (run && std::getline(std::cin, cmd))
	{
		if (std::cin.eof() || (!cmd.compare("n") || !cmd.compare("n ") || !cmd.compare("N") || !cmd.compare("N ")))
		{
			std::cout << "Program will now execute default main, bye." << std::endl;
			run = false;
		}		
		else if (!cmd.compare("y") || !cmd.compare("y ") || !cmd.compare("Y") || !cmd.compare("Y "))
		{
			godmode = true;
			GodMode.show_cmds();
			GodMode.greetings();
			run = false;
		}
		else
			std::cout << "We did not understood, be more SPECIFIC.\nEntering GODMODE ? y/n\n" << std::endl;
		cmd.clear();
	}
	
	if (godmode)
	{
		run = true;
		std::cout << ran_color() << "> " << RESET;
		while (run && std::getline(std::cin, cmd))
		{
			// system("clear");
			if (std::cin.eof() == true)
			{
				std::cout << "You pressed ^D, Bye." << std::endl;
				sleep(1);
				exit(0);
			}
			else if (!cmd.compare("help") || !cmd.compare("h"))
				GodMode.show_cmds();
			else if (!cmd.compare("exit"))
			{
				std::cout << "Bye <3" << std::endl;
				run = false;
				continue ;
			}
			// else if (!cmd.compare("downgrade") || !cmd.compare("d"))
			// {

			// }
			// else if (!cmd.compare("new") || !cmd.compare("n"))
			// 	GodMode.new_human();
			// else if (!cmd.compare("show") || !cmd.compare("s"))
			// 	GodMode.show_humans();
			if (cmd[0] == '\n')
				GodMode.greetings();
			cmd.clear();
			
			std::cout << ran_color() << "> " << RESET << std::flush;
			
		}
	}
	else
	{
		sleep(1);
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
	}
	return (0);
}

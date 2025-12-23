/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:33:53 by ilymegy           #+#    #+#             */
/*   Updated: 2024/11/26 17:33:55 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/easyfind.hpp"
#include "../inc/style.hpp"

#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main()
{
	std::cout << YELLOW "Test vector container\n"<< RESET;
	std::vector<int> v;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	try
	{
		std::cout << "searching number 5 :\t" << *easyfind(v, 5) << std::endl;
		std::cout << "searching number 20 :\t" << *easyfind(v, 20) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


	std::cout << YELLOW "Test list container\n"<< RESET;
	std::list<int> l;

	for (int i = 0; i < 20; i++)
	{
		l.push_back(i);
	}
	try
	{
		std::cout << "searching number 0 :\t" << *easyfind(l, 0) << std::endl;
		std::cout << "searching number 1000 :\t" << *easyfind(l, 1000) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


	std::cout << YELLOW "Test deque container\n"<< RESET;
	std::deque<int> d;

	for (int i = 0; i < 350; i++)
	{
		d.push_back(i);
	}

	try
	{
		std::cout << "searching number 349 :\t" << *easyfind(d, 349) << std::endl;
		std::cout << "searching number 560 :\t" << *easyfind(d, 560) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return (0);
}

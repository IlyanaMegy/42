/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:02:12 by ilymegy           #+#    #+#             */
/*   Updated: 2024/03/11 18:02:14 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

int	main(int ac, char **av)
{
	std::string word;
	if (ac != 4)
	{
		std::cout << "invalid number of arguments." << std::endl;
		return (1);
	}
	std::ifstream myfile(av[1]);
	if (myfile.is_open())
	{
		std::string file = av[1];
		std::string s1 = av[2];
		std::string s2 = av[3];
		std::ofstream outfile((file + ".replace").c_str());
		if (outfile.is_open())
		{
			while (myfile.good() && myfile >> word)
			{
				if (word.compare(s1) == 0)
					outfile << s2;
				else
					outfile << word;
				if (myfile.peek() == '\n')
					outfile << std::endl;
				else if (myfile.peek() == ' ')
					outfile << " ";
			}
			outfile.close();
		}
		else
		{
			std::cout << "could not open outfile." << std::endl;
			myfile.close();
			return (1);
		}
		myfile.close();
		return (0);
	}
	std::cout << "could not open infile." << std::endl;
	return (1);
}

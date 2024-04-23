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

void	replaceStrings(std::ofstream &fileOut, std::string s1, std::string s2,
		std::string input)
{
	size_t	pos;
	size_t	toSkip;

	pos = input.find(s1);
	if (pos == std::string::npos)
	{
		fileOut << input;
		return ;
	}
	else
	{
		fileOut << input.substr(0, pos);
		fileOut << s2;
		toSkip = pos + s1.length();
		replaceStrings(fileOut, s1, s2, input.substr(toSkip));
	}
}

int	main(int ac, char **av)
{
	std::ifstream myfile;
	std::ofstream outfile;
	std::string buffer;
	if (ac != 4)
	{
		std::cout << "invalid number of arguments." << std::endl;
		return (1);
	}
	std::string file = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];
	myfile.open(av[1]);
	if (myfile.is_open())
	{
		outfile.open((file + ".replace").c_str());
		if (outfile.is_open())
		{
			while (getline(myfile, buffer))
				replaceStrings(outfile, s1, s2, buffer + '\n');
			myfile.close();
			outfile.close();
			return (0);
		}
		std::cout << "could not open outfile." << std::endl;
		myfile.close();
		return (1);
	}
	std::cout << "could not open infile." << std::endl;
	return (1);
}

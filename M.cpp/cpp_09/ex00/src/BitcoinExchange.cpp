/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 21:14:01 by ilymegy           #+#    #+#             */
/*   Updated: 2024/12/06 21:14:02 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::~BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(BitcoinExchange const &src){*this = src; }

BitcoinExchange::BitcoinExchange(std::string dB): _filename(dB)
{
	try
	{
		readDB();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &src)
{
	if (this != &src)
	{
		_filename = src._filename;
		_rates = src._rates;
	}
	return *this;
}

bool BitcoinExchange::isDateOK(const std::string &date)
{
	if (date.size() != 10) return (false);
	for (size_t i = 0; i < data.size(); i++)
	{
		if (i == 4 || i == 7)
			if (date[i] != '-')
				return (false);
		else
			if (!isdigit(date[i]))
				return (false);
	}
	int y = std::atoi(date.substr(0, 4).c_str());
	int m = std::atoi(date.substr(5, 2).c_str());
	int d = std::atoi(date.substr(8, 2).c_str());

	if (y < 2009 || y > 2100) return (false);
	if (m < 1 || m > 12) return (false);
	if (d < 1 || d > 31) return (false);
	return (true);
}

double BitcoinExchange::getValidPrice(const std::string &price)
{
	double priceVal;
	std::istringstream priceStream(price);

	if (!(priceStream >> priceVal)) return (-1);
	if (priceVal < 0) return (-1);
	if (priceVal > 1000) return (-1);
	return (priceVal);
}

void BitcoinExchange::readDB()
{
	std::ifstream	file(_filename);
	if (!file.is_open())
		// Exception

	std::string line;
	getline(file, line);
	if (line != "date | value")
		// Exception

	while (getline(file, line))
	{
		std::string date;
		std::string exchangeRateStr;
		double priceValue;
		std::istringstream ss(line);

		std::getline(iss, date, ',');
		std::getline(iss, exchangeRateStr);

		if (!isDateOK(date))
			// Exception

		for (size_t i = 0; i < exchangeRateStr.size(); i++)
		{
			if (exchangeRateStr[i] == ',')
				exchangeRateStr[i] = '.';
			else if (!isdigit(exchangeRateStr[i]) && exchangeRateStr[i] != '.')
				// Exception
		}
	}
}
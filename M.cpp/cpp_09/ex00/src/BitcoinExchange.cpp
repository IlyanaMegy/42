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
BitcoinExchange::BitcoinExchange(BitcoinExchange const &src): _rates(src._rates){}
BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &src)
{
	if (this != &src)
		_rates = src._rates;
	return *this;
}

// BitcoinExchange::BitcoinExchange(std::string dB): _filename(dB)
// {
// 	try
// 	{
// 		readDB();
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// }

static bool isNotSpace(char c)
{
    return !std::isspace(static_cast<unsigned char>(c));
}

// Supprime les espaces en tête de la chaîne
static std::string& ltrim(std::string &s)
{
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), isNotSpace));
    return s;
}

// Supprime les espaces en queue de la chaîne
static std::string& rtrim(std::string &s)
{
    s.erase(std::find_if(s.rbegin(), s.rend(), isNotSpace).base(), s.end());
    return s;
}

// Supprime les espaces en tête et en queue de la chaîne
std::string& trim(std::string &s)
{
    return ltrim(rtrim(s));
}

void BitcoinExchange::readDB(const std::string &filename)
{
	std::ifstream	file(filename.c_str());
	if (!file)
		// Exception

	std::string line, date;
	double rate;
	if (std::getline(file, line))
		if (line != "date,exchange_rate")
			// Exception
	std::istringstream ss(line);

	/* Extract the date and rate from the line */
	if (std::getline(ss, date, ',') && (ss >> rate))
		_rates[date] = rate;

	while (getline(file, line))
	{
		std::istringstream ss(line);

		// std::getline(iss, date, ',');
		// std::getline(iss, exchangeRateStr);
		if (getline(ss, date, ',') && (ss >> rate))
		{
			if (!isDateOK(date))
			// Exception
			_rates[date] = rate;
		}
	}
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


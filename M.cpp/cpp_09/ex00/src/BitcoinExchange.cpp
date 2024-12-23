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

BitcoinExchange::BitcoinExchange(){readDB(); }
BitcoinExchange::~BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(BitcoinExchange const &src): _rates(src._rates){}
BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &src)
{
	if (this != &src)
		_rates = src._rates;
	return *this;
}

std::map<std::string, double> const &BitcoinExchange::getRates() const
{
	return (_rates);
}

void BitcoinExchange::readDB()
{
	std::ifstream file("data.csv");
	if (!file.is_open())
		throw InvalidFileException();

	std::string line;
	if (std::getline(file, line))
	{
		std::cout << "line : " << line << "." << std::endl;
		if (line != "date,exchange_rate")
			throw InvalidColumnFormat();
	}
	while (std::getline(file, line))
	{
		std::string date, price;
		std::istringstream ss(line);
		std::getline(ss, date, ',');
		std::getline(ss, price, ',');

		double priceVal;
		std::istringstream priceStream(price);
		if (!(priceStream >> priceVal))
			throw InvalidPriceFormat();
		_rates[date] = priceVal;
	}
	file.close();
}

bool BitcoinExchange::isDateOK(const std::string &date)
{
	if (date.size() != 10) return (false);
	for (size_t i = 0; i < date.size(); i++)
	{
		if (i == 4 || i == 7)
		{
			if (date[i] != '-')
				return (false);
		}
		else if (!isdigit(date[i]))
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

double BitcoinExchange::isValueOK(const std::string &price)
{
	double priceVal;
	std::istringstream priceStream(price);

	if (!(priceStream >> priceVal))
	{
		std::cout << "Error: bad value input => " << priceVal << std::endl;
		return (-1);
	}
	if (priceVal < 0) 
	{
		std::cout << "Error: not a positive number => " << priceVal << std::endl;
		return (-1);
	}
	// if (priceVal > 1000) 
	// {
	// 	std::cout << "Error: too large number => " << priceVal << std::endl;
	// 	return (-1);		
	// }
	return (priceVal);
}

void BitcoinExchange::multiplyWithQuote(std::string const &date, double price)
{
	std::map<std::string, double>::iterator it = _rates.find(date);
	if (it != _rates.end())
		std::cout << date << " | " << price << " | " << price * it->second << std::endl;
	else
	{
		std::map<std::string, double>::iterator it2 = _rates.lower_bound(date);
		if (it2 == _rates.begin())
			std::cout << date << " | " << price << " | " << price * it2->second << std::endl;
		else
		{
			it2--;
			std::cout << date << " | " << price << " | " << price * it2->second << std::endl;
		}
	}
}

void BitcoinExchange::execute(char const *fileName)
{
	std::ifstream file(fileName);
	if (!file.is_open())
		throw InvalidFileException();

	std::string line;
	std::getline(file, line);
	if (line != "date,exchange_rate")
		throw InvalidColumnFormat();

	while (std::getline(file, line))
	{
		std::string date, valueStr;
		double priceVal;
		std::istringstream ss(line);
		std::getline(ss, date, ',');
		std::getline(ss, valueStr, ',');

		if (isDateOK(date) == false)
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}
		if(!valueStr.empty())
			valueStr = valueStr.erase(0, 1);
		priceVal = isValueOK(valueStr);
		if (priceVal != -1)
			multiplyWithQuote(date, priceVal);
	}
	file.close();
}

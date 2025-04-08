#pragma once
#ifndef BITCOINEXCHANGE__HPP
# define BITCOINEXCHANGE__HPP

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cstdlib>
#include <algorithm>
#include <ostream>
#include <cctype>
#include "../inc/style.hpp"

#define YEAR_LENGTH 4
#define MONTH_LENGTH 2
#define DAY_LENGTH 2

#define FEBRUARY 2
#define APRIL 4
#define JUNE 6
#define SEPTEMBER 9
#define NOVEMBER 11

class BitcoinExchange
{
  private:
	std::map<int, std::string> _input;
	std::map<std::string, double> _rates;

	
	bool isDateOK(const std::string &date);
	bool isValueOK(const std::string &value);
	void multiplyWithQuote(std::string const &date, double price);
	void calculate(std::map<int, std::string>::iterator &it);

  public:
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const &src);
	BitcoinExchange &operator=(BitcoinExchange const &src);
	~BitcoinExchange();

	double getRates(const std::string &date) const;
	void readDB(const std::string & filename);
	void execute(const std::string &fileName);

	class InvalidFileException : public std::exception
	{
		public:
		virtual const char *what() const throw()
		{
			return ("Error: Invalid file.");
		}
	};

	class InvalidColumnFormat : public std::exception
	{
		public:
		virtual const char *what() const throw()
		{
			return ("Invalid column format. Expected 'date,exchange_rate'");
		}
	};

	class InvalidDateFormat : public std::exception
	{
		public:
		virtual const char *what() const throw()
		{
			return ("Invalid date format. Expected 'YYYY-MM-DD'");
		}
	};

	class InvalidPriceFormat : public std::exception
	{
		public:
		virtual const char *what() const throw()
		{
			return ("Invalid price format. Expected a number between 0.0 and 1000.0");
		}
	};
};
#endif

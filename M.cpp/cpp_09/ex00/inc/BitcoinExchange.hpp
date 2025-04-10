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
	double _value;
	double _result;
	std::map<std::string, double> _dB;

	void addDB(void);
	bool isDateOK(const std::string &date);
	int checkValue(const std::string &value);
	void calculate(std::map<int, std::string>::iterator &it);

  public:
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const &src);
	BitcoinExchange &operator=(BitcoinExchange const &src);
	~BitcoinExchange();

	void readInput(const std::string &filename);
	void execute(void);
	void printResult(void);

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
			return ("Invalid column format. Expected 'date | exchange_rate'");
		}
	};
};
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 21:14:11 by ilymegy           #+#    #+#             */
/*   Updated: 2024/12/06 21:14:18 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE__HPP
# define BITCOINEXCHANGE__HPP

# include <cstdlib>
# include <exception>
# include <fstream>
# include <iostream>
# include <map>
# include <sstream>
# include <string>

class BitcoinExchange
{
  private:
	std::map<std::string, double> _rates;
	void readDB();
	bool isDateOK(const std::string &date);
	double isValueOK(const std::string &value);
	void multiplyWithQuote(std::string const &date, double price);

  public:
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const &src);
	BitcoinExchange &operator=(BitcoinExchange const &src);
	~BitcoinExchange();

	std::map<std::string, double> const &getRates() const;
	void execute(char const *fileName);

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

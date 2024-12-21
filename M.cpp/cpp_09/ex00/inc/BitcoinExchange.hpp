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

# include <exception>
# include <iostream>
#include <fstream>
# include <map>
# include <sstream>
# include <string>

class BitcoinExchange
{
  private:
	// std::string _filename;
	std::map<std::string, double> _rates;
	bool isDateOK(const std::string &date);
	bool isValueOK(const std::string &value);
	BitcoinExchange();	

  public:
	BitcoinExchange(std::string dB);
	BitcoinExchange(BitcoinExchange const &src);
	BitcoinExchange &operator=(BitcoinExchange const &src);
	~BitcoinExchange();

	void readDB(const std::string &filename);
	bool getValidPrice(const std::string &price);
	std::pair<std::string, double> getRateForDate(const std::string &date);

	// Exceptions
};

#endif
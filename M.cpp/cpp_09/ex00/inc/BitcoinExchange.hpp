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
# include <map>

class BitcoinExchange
{
  private:
  public:
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const &src);
	BitcoinExchange &operator=(BitcoinExchange const &src);
	~BitcoinExchange();
};

#endif
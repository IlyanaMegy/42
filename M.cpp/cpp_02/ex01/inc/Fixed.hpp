/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:43:54 by ilymegy           #+#    #+#             */
/*   Updated: 2024/03/13 18:43:55 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath>
# include <iostream>

class Fixed
{
  private:
	int _fixed;
	static const int _fract_bits = 8;

  public:
	//Constructors
	Fixed(void);              //	Default constructor
	Fixed(Fixed const &copy); //	Copy constructor
	Fixed(int const nb);
	Fixed(float const nb);

	//	Assignment operator
	Fixed &operator=(Fixed const &src);

	//	Destructor
	~Fixed(void);

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream    &operator<<(std::ostream &o, Fixed const &fixed);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:52:22 by ilymegy           #+#    #+#             */
/*   Updated: 2024/03/13 16:52:23 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
  private:
	int _fixed;
	static const int _fract_bits = 8;

  public:
	Fixed(void);                        //	Default constructor
	Fixed(Fixed const &copy);           //	Copy constructor
	Fixed &operator=(Fixed const &src); //	Assignment operator
	~Fixed(void);                       //	Destructor

	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif

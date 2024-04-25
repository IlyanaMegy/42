/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:43:48 by ilymegy           #+#    #+#             */
/*   Updated: 2024/03/13 18:43:49 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

Fixed::Fixed(void): _fixed(0)
{
	return ;
}

Fixed::Fixed(Fixed const &copy)
{
	*this = copy;
}

Fixed::Fixed(const int nb)
{
	this->_fixed = nb << this->_fract_bits;
}

Fixed::Fixed(const float nb)
{
	this->_fixed = roundf(nb * (1 << this->_fract_bits));
}

Fixed::~Fixed(void)
{
	return ;
}

Fixed &Fixed::operator=(const Fixed &src)
{
	if (this != &src)
		this->_fixed = src.getRawBits();
	return (*this);
}

bool Fixed::operator>(Fixed fixed) const
{
	return (this->toFloat() > fixed.toFloat());
}

bool Fixed::operator<(Fixed fixed) const
{
	return (this->toFloat() < fixed.toFloat());
}

bool Fixed::operator>=(Fixed fixed) const
{
	return (this->toFloat() >= fixed.toFloat());
}

bool Fixed::operator<=(Fixed fixed) const
{
	return (this->toFloat() <= fixed.toFloat());
}

bool Fixed::operator==(Fixed fixed) const
{
	return (this->toFloat() == fixed.toFloat());
}

bool Fixed::operator!=(Fixed fixed) const
{
	return (this->toFloat() != fixed.toFloat());
}

float Fixed::operator+(Fixed fixed) const
{
	return (this->toFloat() + fixed.toFloat());
}

float Fixed::operator-(Fixed fixed) const
{
	return (this->toFloat() - fixed.toFloat());
}

float Fixed::operator*(Fixed fixed) const
{
	return (this->toFloat() * fixed.toFloat());
}

float Fixed::operator/(Fixed fixed) const
{
	return (this->toFloat() / fixed.toFloat());
}

Fixed Fixed::operator++()
{
	this->_fixed++;
	return (*this);
}

Fixed Fixed::operator--()
{
	this->_fixed--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed	tmp;

	tmp = *this;
	++this->_fixed;
	return (tmp);
}

Fixed Fixed::operator--(int)
{
	Fixed	tmp;

	tmp = *this;
	--this->_fixed;
	return (tmp);
}

const Fixed &Fixed::min(const Fixed &first, const Fixed &second)
{
	if (first.toFloat() >= second.toFloat())
		return (second);
	return (first);
}

Fixed &Fixed::min(Fixed &first, Fixed &second)
{
	if (first.toFloat() >= second.toFloat())
		return (second);
	return (first);
}

const Fixed &Fixed::max(const Fixed &first, const Fixed &second)
{
	if (first.toFloat() >= second.toFloat())
		return (first);
	return (second);
}

Fixed &Fixed::max(Fixed &first, Fixed &second)
{
	if (first.toFloat() >= second.toFloat())
		return (first);
	return (second);
}

int Fixed::getRawBits(void) const
{
	return (this->_fixed);
}

void Fixed::setRawBits(int const raw)
{
	this->_fixed = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)this->_fixed / (float)(1 << this->_fract_bits));
}

int Fixed::toInt(void) const
{
	return (this->_fixed >> this->_fract_bits);
}

std::ostream &operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}

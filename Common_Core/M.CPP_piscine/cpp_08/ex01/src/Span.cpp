/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:31:10 by ilymegy           #+#    #+#             */
/*   Updated: 2024/11/28 15:31:11 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

Span::~Span(){}
Span::Span(): _n(0){}
Span::Span(unsigned int n): _n(n){}
Span::Span(Span const &src){*this = src; }
Span &Span::operator=(Span const &src)
{
	if (this != &src)
	{
		this->_n = src._n;
		this->_v = src._v;
	}
	return *this;
}

void Span::addNumber(int n)
{
	if (_v.size() >= _n)
		throw FullContainerException();
	_v.push_back(n);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_v.size() + std::distance(begin, end) >= _n)
		throw FullContainerException();
	_v.insert(_v.end(), begin, end);
}

int	Span::shortestSpan()
{
	if (_v.size() <= 1)
		throw NotEnoughNumbersException();
	std::vector<int> tmp = _v;
	std::sort(tmp.begin(), tmp.end());
	int min = tmp[1] - tmp[0];
	for (unsigned int i = 1; i < tmp.size(); i++)
	{
		if (tmp[i] - tmp[i - 1] < min)
			min = tmp[i] - tmp[i - 1];
	}
	return (min);
}

int Span::longestSpan()
{
	if (_v.size() <= 1)
		throw NotEnoughNumbersException();
	std::vector<int> tmp = _v;
	std::sort(tmp.begin(), tmp.end());
	return (tmp[tmp.size() - 1] - tmp[0]);
}

const char *Span::FullContainerException::what() const throw()
{
	return ("Container is full");
}

const char *Span::NotEnoughNumbersException::what() const throw()
{
	return ("Not enough numbers in container");
}

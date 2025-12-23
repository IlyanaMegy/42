/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:30:57 by ilymegy           #+#    #+#             */
/*   Updated: 2024/11/28 15:30:58 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

class Span
{
private:
	unsigned int _n;
	std::vector<int> _v;
public:
	Span();
	Span(unsigned int n);
	Span(Span const &src);
	Span &operator=(Span const &src);
	~Span();

	void addNumber(int n);
	int shortestSpan();
	int longestSpan();
	void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);

	class FullContainerException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class NotEnoughNumbersException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:40:29 by ilymegy           #+#    #+#             */
/*   Updated: 2024/11/26 16:40:30 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>
# include <iostream>

template <typename T>
class Array
{
  private:
	T *_array;
	unsigned int _size;

  public:
	Array();
	Array(unsigned int n);
	Array(Array const &src);
	~Array();

	Array &operator=(Array const &src);
	T &operator[](unsigned int i);
	T const &operator[](unsigned int i) const;

	unsigned int size() const;

	class OutOfBoundsException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};
};

# include "Array.tpp"
#endif

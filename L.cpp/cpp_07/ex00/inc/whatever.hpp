/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:24:06 by ilymegy           #+#    #+#             */
/*   Updated: 2024/11/26 16:24:07 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Indicate to the compilator that T refer to a variable's type
// that will follow some parameters
template <typename T>
void	swap(T &a, T &b)
{
	T	tmp = a;
	a = b;
	b = tmp;
}

// here variables a, b won't me modified
// the function will accept a const reference of a and b as parameters
// the function returns a referance on a constant instance (const &max)
template <typename T>
const T &minus(T const &a, T const &b)
{
	return ((a < b) ? a : b);
}

template <typename T>
const T &maxi(T const &a, T const &b)
{
	return ((a > b) ? a : b);
}

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

// Indique que T est un paramètre de type
template<typename T>
void	swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
const T&	min(T &a, T &b)
{
	return ((a < b) ? a : b);
}

template<typename T>
const T&	max(T &a, T &b)
{
	return ((a > b) ? a : b);
}

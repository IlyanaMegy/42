/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:32:16 by ilymegy           #+#    #+#             */
/*   Updated: 2024/11/26 16:32:16 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
void	iter(T const *array, size_t const len, void (*f)(T const &))
{
	for (size_t i = 0; i < len; i++)
		f(array[i]);
}

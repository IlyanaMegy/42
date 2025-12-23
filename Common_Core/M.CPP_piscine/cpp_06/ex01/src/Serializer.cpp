/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <ilyanamegy@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:33:06 by ilymegy           #+#    #+#             */
/*   Updated: 2025/01/13 21:54:36 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serializer.hpp"

Serializer::Serializer(){};
Serializer::Serializer(Serializer const &src){(void)src;}
Serializer &Serializer::operator=(Serializer const &src){(void)src; return (*this);}
Serializer::~Serializer(){};

uintptr_t	Serializer::serialize(Data* ptr)
{	
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*		Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

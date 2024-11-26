/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:33:06 by ilymegy           #+#    #+#             */
/*   Updated: 2024/11/26 14:33:09 by ilymegy          ###   ########.fr       */
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

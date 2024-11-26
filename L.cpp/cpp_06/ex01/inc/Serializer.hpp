/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:33:18 by ilymegy           #+#    #+#             */
/*   Updated: 2024/11/26 14:33:20 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
// #include <cstdint>
#include <iostream>
#include <string>

typedef struct Data
{
	std::string name;
	int		number;
	Data	*next;
}			Data;

class Serializer
{
  private:
	Serializer();
	~Serializer();
	Serializer(Serializer const &src);
	Serializer &operator=(Serializer const &src);

  public:
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
};

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:41:29 by ilymegy           #+#    #+#             */
/*   Updated: 2024/04/04 13:41:30 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
  public:
	Dog(void);
	Dog(Dog const &copy);
	Dog &operator=(Dog const &assign);
	~Dog(void);

	void makeSound(void) const;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:47:25 by ilymegy           #+#    #+#             */
/*   Updated: 2024/04/09 14:47:26 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
  private:
	Brain *_brain;

  public:
	Dog(void);
	Dog(Dog const &copy);
	Dog &operator=(Dog const &assign);
	~Dog(void);

	void makeSound(void) const;
	void addIdea(std::string idea);
	void expressIdeas(void) const;
};

#endif

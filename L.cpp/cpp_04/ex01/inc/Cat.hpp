/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:47:32 by ilymegy           #+#    #+#             */
/*   Updated: 2024/04/09 14:47:33 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
  private:
	Brain *_brain;

  public:
	Cat(void);
	Cat(Cat const &copy);
	Cat &operator=(Cat const &assign);
	~Cat(void);

	void makeSound(void) const;
};

#endif

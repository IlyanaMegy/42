/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:44:39 by ilymegy           #+#    #+#             */
/*   Updated: 2024/04/23 13:44:40 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{
  private:
	Brain *_brain;

  public:
	Cat(void);
	Cat(Cat const &copy);
	Cat &operator=(Cat const &assign);
	~Cat(void);

	void makeSound(void) const;
	void addIdeas(std::string idea);
	void expressIdeas(void) const;
};

#endif

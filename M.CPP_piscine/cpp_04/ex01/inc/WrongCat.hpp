/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:42:44 by ilymegy           #+#    #+#             */
/*   Updated: 2024/04/10 10:42:46 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "Brain.hpp"
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
  private:
	Brain *_brain;

  public:
	WrongCat(void);
	WrongCat(WrongCat const &copy);
	WrongCat &operator=(WrongCat const &assign);
	~WrongCat(void);

	void makeSound(void) const;
	void addIdeas(std::string idea);
	void expressIdeas(void) const;
};

#endif

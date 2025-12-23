/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:41:16 by ilymegy           #+#    #+#             */
/*   Updated: 2024/04/04 13:41:20 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iomanip>
# include <iostream>

# define BLACK "\033[30m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define ORANGE "\033[38;5;208m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"
# define UNDERLINE "\033[4m"
# define RESET "\033[0m"

class Animal
{
  protected:
	std::string _type;

  public:
	Animal();
	Animal(Animal const &copy);
	Animal &operator=(Animal const &assign);
	virtual ~Animal();

	std::string getType() const;
	virtual void makeSound() const;
};

#endif

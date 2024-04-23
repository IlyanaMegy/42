/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:43:52 by ilymegy           #+#    #+#             */
/*   Updated: 2024/04/23 13:43:54 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# define BLACK "\033[30m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define ORANGE "\033[38;5;208m"
# define MAGENTA "\033[35m"
# define PINK "\033[38;5;206m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"
# define UNDERLINE "\033[4m"
# define RESET "\033[0m"

# include <cstdio>
# include <cstdlib>
# include <iomanip>
# include <iostream>

class WrongAnimal
{
  protected:
	std::string _type;

  public:
	WrongAnimal(void);
	WrongAnimal(WrongAnimal const &copy);
	WrongAnimal &operator=(WrongAnimal const &assign);
	~WrongAnimal(void);

	void makeSound(void) const;
	std::string getType(void) const;
};

#endif

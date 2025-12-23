/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:52:22 by ilymegy           #+#    #+#             */
/*   Updated: 2024/04/23 13:52:23 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP
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

class AMateria
{
  protected:
  public:
	AMateria(std::string const &type);
	AMateria(AMateria const &copy);
	AMateria &operator=(AMateria const &assign);
	virtual ~AMateria(void);
	std::string const &getType() const;
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);
};
#endif

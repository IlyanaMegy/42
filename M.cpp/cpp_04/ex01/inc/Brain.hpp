/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:47:38 by ilymegy           #+#    #+#             */
/*   Updated: 2024/04/09 14:47:39 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include "Animal.hpp"
# include <iomanip>
# include <iostream>

class Brain
{
  private:
	std::string _ideas[100];

  public:
	Brain(void);
	Brain(Brain const &copy);
	Brain &operator=(Brain const &assign);
	virtual ~Brain(void);

	std::string getIdea(unsigned int idx) const;
	void setIdea(unsigned int idx, std::string idea);
};

#endif

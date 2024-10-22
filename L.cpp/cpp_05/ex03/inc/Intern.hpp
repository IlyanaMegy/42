/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 21:00:25 by ilymegy           #+#    #+#             */
/*   Updated: 2024/10/17 21:00:27 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "PPForm.hpp"
# include "RRForm.hpp"
# include "SCForm.hpp"

class AForm;
class PPForm;
class RRForm;
class SCForm;
class Intern
{
private:
	/* data */
public:
	Intern();
	Intern(Intern const &src);
	Intern &operator=(Intern const &src);
	~Intern();

	AForm *makeForm(const std::string form, const std::string target);
};


#endif

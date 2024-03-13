/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:13:58 by ilymegy           #+#    #+#             */
/*   Updated: 2024/03/12 16:13:59 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

int	main(void)
{
	Harl harl;

	harl.complain("debug");
	std::cout << std::endl;

	harl.complain("info");
	std::cout << std::endl;
	
	harl.complain("warning");
	std::cout << std::endl;
	
	harl.complain("error");
	std::cout << std::endl;
	
	harl.complain("critical");
	std::cout << std::endl;
	return (0);
}

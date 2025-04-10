/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 19:48:46 by lbarry            #+#    #+#             */
/*   Updated: 2024/10/02 17:39:05 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	try
	{
		if (argc < 2)
			throw std::invalid_argument("Error: please provide at least 2 arguments");

		PmergeMeVector VecSort(argc, argv);
		clock_t	vector_time = clock();
		VecSort.lets_ford_and_johnson();
		vector_time = clock() - vector_time;
		std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << (float)vector_time * 1000 / CLOCKS_PER_SEC << "ms" << std::endl;

		PmergeMeDeque DeqSort(argc, argv);
		clock_t	deque_time = clock();
		DeqSort.lets_ford_and_johnson();
		deque_time = clock() - deque_time;
		std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque : " << (float)deque_time * 1000 / CLOCKS_PER_SEC << "ms" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}

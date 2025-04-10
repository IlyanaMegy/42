/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 19:55:21 by lbarry            #+#    #+#             */
/*   Updated: 2024/10/02 02:07:25 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>

class PmergeMeVector
{
	private:
		std::vector<int>					_args;
		std::vector<std::pair<int, int> >	_pairs;
		std::vector<int>					_smallest_unsorted;
		std::vector<int>					_sorted;
		std::vector<int>					_jacobsthal;
		std::vector<int>					_indexes;
		bool	check_duplicates(int argc, char **argv);
		bool	check_negatives(int argc, char **argv);
		void	make_pairs(void);
		void	sort_within_pairs(void);
		void	sort_between_pairs(void);
		void	divide_sort_merge(std::vector<std::pair<int, int> > &pairs, int begin, int end);
		void	merge_sort(std::vector<std::pair<int, int> > &pairs, int begin, int mid, int end);
		void	create_final_sequence(void);
		void	split_pairs(void);
		void	stock_jacobsthal_numbers(void);
		int		jacobsthal(int n);
		void	create_insertion_indexes(void);
		void	insert_into_sorted(void);
		int		binary_search(std::vector<int> sorted, int to_push, int begin, int end);

	public:
		PmergeMeVector(void);
		PmergeMeVector(int argc, char **argv);
		PmergeMeVector(PmergeMeVector const &copy);
		~PmergeMeVector(void);
		PmergeMeVector	&operator=(PmergeMeVector const &copy);
		void		lets_ford_and_johnson(void);
};

class PmergeMeDeque
{
	private:
		std::deque<int>						_args;
		std::deque<std::pair<int, int> >	_pairs;
		std::deque<int>						_smallest_unsorted;
		std::deque<int>						_sorted;
		std::deque<int>						_jacobsthal;
		std::deque<int>						_indexes;
		bool	check_duplicates(int argc, char **argv);
		bool	check_negatives(int argc, char **argv);
		void	make_pairs(void);
		void	sort_within_pairs(void);
		void	sort_between_pairs(void);
		void	divide_sort_merge(std::deque<std::pair<int, int> > &pairs, int begin, int end);
		void	merge_sort(std::deque<std::pair<int, int> > &pairs, int begin, int mid, int end);
		void	create_final_sequence(void);
		void	split_pairs(void);
		void	stock_jacobsthal_numbers(void);
		int		jacobsthal(int n);
		void	create_insertion_indexes(void);
		void	insert_into_sorted(void);
		int		binary_search(std::deque<int> sorted, int to_push, int begin, int end);

	public:
		PmergeMeDeque(void);
		PmergeMeDeque(int argc, char **argv);
		PmergeMeDeque(PmergeMeDeque const &copy);
		~PmergeMeDeque(void);
		PmergeMeDeque	&operator=(PmergeMeDeque const &copy);
		void		lets_ford_and_johnson(void);
};

#endif



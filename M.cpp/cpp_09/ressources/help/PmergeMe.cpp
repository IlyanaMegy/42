/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarry <lbarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 19:59:19 by lbarry            #+#    #+#             */
/*   Updated: 2024/10/02 17:41:13 by lbarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// ------------------------------------- VECTOR -------------------------------

// --------------- orthodox canonical form ---------------

PmergeMeVector::PmergeMeVector(void)
{
	throw std::invalid_argument("Error: please provide at least 2 arguments");
}

PmergeMeVector::PmergeMeVector(int argc, char **argv)
{
	if (argc < 3 || !argv || !argv[1])
		throw std::invalid_argument("Error: please provide at least 2 arguments");
	if (!check_duplicates(argc, argv))
		throw std::invalid_argument("Error: please provide arguments without duplicates");
	if (!check_negatives(argc, argv))
		throw std::invalid_argument("Error: please provide arguments without negatives");
	for (int i = 1; i < argc; i++)
	{
		std::stringstream ss(argv[i]);
		int arg;
		ss >> arg;
		_args.push_back(arg);
	}
}

PmergeMeVector::PmergeMeVector(PmergeMeVector const &copy)
{
	*this = copy;
}

PmergeMeVector &PmergeMeVector::operator=(PmergeMeVector const &copy)
{
	if (this != &copy)
	{
		_args = copy._args;
	}
	return (*this);
}

PmergeMeVector::~PmergeMeVector(void) {}

// --------------- parsing functions ---------------

bool PmergeMeVector::check_duplicates(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		std::stringstream ss(argv[i]);
		int arg;
		ss >> arg;
		for (int j = i + 1; j < argc; j++)
		{
			std::stringstream ss2(argv[j]);
			int arg2;
			ss2 >> arg2;
			if (arg == arg2)
				return (false);
		}
	}
	return (true);
}

bool	PmergeMeVector::check_negatives(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		std::stringstream ss(argv[i]);
		int arg;
		ss >> arg;
		if (arg < 0)
			return (false);
	}
	return (true);
}

// --------------- algorithm functions ---------------

// finds position to insert smallest number into sorted list
// reduces comparisons by adjusting median each time and only comparing indexes above or below
// returns position to insert
int PmergeMeVector::binary_search(std::vector<int> sorted, int to_push, int begin, int end)
{
	int mid;

	while (begin <= end)
	{
		mid = begin + (end - begin) / 2;
		if (to_push == sorted.at(mid))
			return (mid);

		if (to_push > sorted.at(mid))
			begin = mid + 1;
		else
			end = mid - 1;
	}
	if (to_push > sorted.at(mid))
		return (mid + 1);
	else
		return (mid);
}

// push first smallest into sorted list (always going to be smaller than all the big ones)
// then push the rest using jacobsthal indexes and binary search to compare each time
// insert straggler if original number sequence was odd
void	PmergeMeVector::insert_into_sorted(void)
{
	_sorted.insert(_sorted.begin(), _smallest_unsorted[0]);
	for (std::vector<int>::iterator it = _indexes.begin(); it < _indexes.end(); it++)
	{
		int to_push = _smallest_unsorted.at(*it - 1);
			int pos = binary_search(_sorted, to_push, 0, _sorted.size() - 1);
		_sorted.insert(_sorted.begin() + pos, to_push);
	}
	if (_args.size() % 2 != 0)
	{
		int to_push = _args.at(_args.size() - 1);
		int pos = binary_search(_sorted, to_push, 0, _sorted.size() - 1);
		_sorted.insert(_sorted.begin() + pos, to_push);
	}
}

// starting with [3], go to jacobstaal number, then go down until no more indexes left
void	PmergeMeVector::create_insertion_indexes(void)
{
	if (_smallest_unsorted.empty())
		return;

	size_t last_pos = 1;
	for (size_t i = 0; i < _jacobsthal.size(); i++)
	{
		_indexes.push_back(_jacobsthal.at(i));
		size_t j = _jacobsthal.at(i) - 1;
		while (j > last_pos)
		{
			_indexes.push_back(j);
			j--;
		}
		last_pos = _jacobsthal.at(i);
	}
	while (last_pos++ < _sorted.size())
		_indexes.push_back(last_pos);
}

// recursive jacobsthal number calculator
int	PmergeMeVector::jacobsthal(int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}

// create vector of jaobsthal numbers
void	PmergeMeVector::stock_jacobsthal_numbers(void)
{
	size_t size;
	size_t jcobstalIndex;
	int index;

	size = _smallest_unsorted.size();
	index = 3;
	while ((jcobstalIndex = jacobsthal(index)) <= size)
	{
		_jacobsthal.push_back(jcobstalIndex);
		index++;
	}
}

// biggest numbers = sorted sequence, their pairs --> smallest unsorted sequence
void	PmergeMeVector::split_pairs(void)
{
	for(size_t i = 0; i < _pairs.size(); i++)
	{
		_smallest_unsorted.push_back(_pairs[i].second);
		_sorted.push_back(_pairs[i].first);
	}
}

void	PmergeMeVector::create_final_sequence(void)
{
	split_pairs();
	stock_jacobsthal_numbers();
	create_insertion_indexes();
	insert_into_sorted();
}

// merge function- sort based on biggest and merge back together
// receives divided chunks of pairs vector
void PmergeMeVector::merge_sort(std::vector<std::pair<int, int> > &pairs, int begin, int mid, int end)
{
	std::vector<std::pair<int, int> > temp;
	int left = begin;
	int right = mid + 1;

	while (left <= mid && right <= end)
	{
		if (pairs[left].first < pairs[right].first)
			temp.push_back(pairs[left++]);
		else
			temp.push_back(pairs[right++]);
	}
	while (left <= mid)
		temp.push_back(pairs[left++]);
	while (right <= end)
		temp.push_back(pairs[right++]);
	for (size_t k = 0; k < temp.size(); k++)
		pairs[begin + k] = temp[k];
}

// merge sort divide_into_subarrays- left and right
// when can't divide any further, calls merge_sort
void	PmergeMeVector::divide_sort_merge(std::vector<std::pair<int, int> > &pairs, int begin, int end)
{
	int mid = 0;

	if (begin >= end)
		return;
	mid = begin + (end - begin) / 2;
	this->divide_sort_merge(pairs, begin, mid);
	this->divide_sort_merge(pairs, mid + 1, end);
	this->merge_sort(pairs, begin, mid, end);
}

// sort between pairs by biggest (merge sort)
// smallest sequence are all attached to biggest still and move too
// use recursion- divide / conquer
void	PmergeMeVector::sort_between_pairs(void)
{
	divide_sort_merge(this->_pairs, 0, this->_pairs.size() - 1);
}

// sort within pairs use binary search/ insert sort (1 comparison)
void	PmergeMeVector::sort_within_pairs(void)
{
	for (size_t i = 0; i < _pairs.size(); i++)
	{
		if (_pairs[i].first < _pairs[i].second)
			std::swap(_pairs[i].first, _pairs[i].second);
	}
}

// make vector pairs by index - [0, 1], [2, 3], etc.
void	PmergeMeVector::make_pairs(void)
{
	size_t new_size;
	if (_args.size() % 2 == 0)
		new_size = _args.size();
	else
		new_size = _args.size() - 1;
	size_t i = 0;
	while(i < new_size)
	{
		_pairs.push_back(std::make_pair(_args[i], _args[i + 1]));
		i += 2;
	}
}

void	PmergeMeVector::lets_ford_and_johnson(void)
{
	make_pairs();
	sort_within_pairs();
	sort_between_pairs();
	create_final_sequence();
	std::cout << "Before: ";
	for (size_t j = 0; j < _args.size(); j++)
		std::cout << _args[j] << " ";
	std::cout << std::endl;
	std::cout << "After:  ";
	for (size_t i = 0; i < _sorted.size(); i++)
		std::cout << _sorted[i] << " ";
	std::cout << std::endl;
}

// ------------------------------------- DEQUE -------------------------------

// --------------- orthodox canonical form ---------------

PmergeMeDeque::PmergeMeDeque(void)
{
	throw std::invalid_argument("Error: please provide at least 2 arguments");
}

PmergeMeDeque::PmergeMeDeque(int argc, char **argv)
{
	if (argc < 3 || !argv || !argv[1])
		throw std::invalid_argument("Error: please provide at least 2 arguments");
	if (!check_duplicates(argc, argv))
		throw std::invalid_argument("Error: please provide arguments without duplicates");
	if (!check_negatives(argc, argv))
		throw std::invalid_argument("Error: please provide arguments without negatives");
	for (int i = 1; i < argc; i++)
	{
		std::stringstream ss(argv[i]);
		int arg;
		ss >> arg;
		_args.push_back(arg);
	}
}

PmergeMeDeque::PmergeMeDeque(PmergeMeDeque const &copy)
{
	*this = copy;
}

PmergeMeDeque &PmergeMeDeque::operator=(PmergeMeDeque const &copy)
{
	if (this != &copy)
	{
		_args = copy._args;
	}
	return (*this);
}

PmergeMeDeque::~PmergeMeDeque(void) {}

// --------------- parsing functions ---------------

bool PmergeMeDeque::check_duplicates(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		std::stringstream ss(argv[i]);
		int arg;
		ss >> arg;
		for (int j = i + 1; j < argc; j++)
		{
			std::stringstream ss2(argv[j]);
			int arg2;
			ss2 >> arg2;
			if (arg == arg2)
				return (false);
		}
	}
	return (true);
}

bool	PmergeMeDeque::check_negatives(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		std::stringstream ss(argv[i]);
		int arg;
		ss >> arg;
		if (arg < 0)
			return (false);
	}
	return (true);
}

// --------------- algorithm functions ---------------

// finds position to insert smallest number into sorted list
// reduces comparisons by adjusting median each time and only comparing indexes above or below
// returns position to insert
int PmergeMeDeque::binary_search(std::deque<int> sorted, int to_push, int begin, int end)
{
	int mid;

	while (begin <= end)
	{
		mid = begin + (end - begin) / 2;
		if (to_push == sorted.at(mid))
			return (mid);

		if (to_push > sorted.at(mid))
			begin = mid + 1;
		else
			end = mid - 1;
	}
	if (to_push > sorted.at(mid))
		return (mid + 1);
	else
		return (mid);
}

// push first smallest into sorted list (always going to be smaller than all the big ones)
// then push the rest using jacobsthal indexes and binary search to compare each time
// insert straggler if original number sequence was odd
void	PmergeMeDeque::insert_into_sorted(void)
{
	_sorted.insert(_sorted.begin(), _smallest_unsorted[0]);
	for (std::deque<int>::iterator it = _indexes.begin(); it < _indexes.end(); it++)
	{
		int to_push = _smallest_unsorted.at(*it - 1);
		int pos = binary_search(_sorted, to_push, 0, _sorted.size() - 1);
		_sorted.insert(_sorted.begin() + pos, to_push);
	}
	if (_args.size() % 2 != 0)
	{
		int to_push = _args.at(_args.size() - 1);
		int pos = binary_search(_sorted, to_push, 0, _sorted.size() - 1);
		_sorted.insert(_sorted.begin() + pos, to_push);
	}
}

// starting with [3], go to jacobstaal number, then go down until no more indexes left
void	PmergeMeDeque::create_insertion_indexes(void)
{
	if (_smallest_unsorted.empty())
		return;

	size_t last_pos = 1;
	for (size_t i = 0; i < _jacobsthal.size(); i++)
	{
		_indexes.push_back(_jacobsthal.at(i));
		size_t j = _jacobsthal.at(i) - 1;
		while (j > last_pos)
		{
			_indexes.push_back(j);
			j--;
		}
		last_pos = _jacobsthal.at(i);
	}
	while (last_pos++ < _sorted.size())
		_indexes.push_back(last_pos);
}

// recursive jacobsthal number calculator
int	PmergeMeDeque::jacobsthal(int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}

// create deque of jaobsthal numbers
void	PmergeMeDeque::stock_jacobsthal_numbers(void)
{
	size_t size;
	size_t jcobstalIndex;
	int index;

	size = _smallest_unsorted.size();
	index = 3;
	while ((jcobstalIndex = jacobsthal(index)) <= size)
	{
		_jacobsthal.push_back(jcobstalIndex);
		index++;
	}
}

// biggest numbers = sorted sequence, their pairs --> smallest unsorted sequence
void	PmergeMeDeque::split_pairs(void)
{
	for(size_t i = 0; i < _pairs.size(); i++)
	{
		_smallest_unsorted.push_back(_pairs[i].second);
		_sorted.push_back(_pairs[i].first);
	}
}

void	PmergeMeDeque::create_final_sequence(void)
{
	split_pairs();
	stock_jacobsthal_numbers();
	create_insertion_indexes();
	insert_into_sorted();
}

// merge function- sort based on biggest and merge back together
// receives divided chunks of pairs deque
void PmergeMeDeque::merge_sort(std::deque<std::pair<int, int> > &pairs, int begin, int mid, int end)
{
	std::deque<std::pair<int, int> > temp;
	int left = begin;
	int right = mid + 1;

	while (left <= mid && right <= end)
	{
		if (pairs[left].first < pairs[right].first)
			temp.push_back(pairs[left++]);
		else
			temp.push_back(pairs[right++]);
	}
	while (left <= mid)
		temp.push_back(pairs[left++]);
	while (right <= end)
		temp.push_back(pairs[right++]);
	for (size_t k = 0; k < temp.size(); k++)
		pairs[begin + k] = temp[k];
}

// merge sort divide_into_subarrays- left and right
// when can't divide any further, calls merge_sort
void	PmergeMeDeque::divide_sort_merge(std::deque<std::pair<int, int> > &pairs, int begin, int end)
{
	int mid = 0;

	if (begin >= end)
		return;
	mid = begin + (end - begin) / 2;
	this->divide_sort_merge(pairs, begin, mid);
	this->divide_sort_merge(pairs, mid + 1, end);
	this->merge_sort(pairs, begin, mid, end);
}

// sort between pairs by biggest (merge sort)
// smallest sequence are all attached to biggest still and move too
// use recursion- divide / conquer
void	PmergeMeDeque::sort_between_pairs(void)
{
	divide_sort_merge(this->_pairs, 0, this->_pairs.size() - 1);
}

// sort within pairs use binary search/ insert sort (1 comparison)
void	PmergeMeDeque::sort_within_pairs(void)
{
	for (size_t i = 0; i < _pairs.size(); i++)
	{
		if (_pairs[i].first < _pairs[i].second)
			std::swap(_pairs[i].first, _pairs[i].second);
	}
}

// make deque pairs by index - [0, 1], [2, 3], etc.
void	PmergeMeDeque::make_pairs(void)
{
	size_t new_size;
	if (_args.size() % 2 == 0)
		new_size = _args.size();
	else
		new_size = _args.size() - 1;
	size_t i = 0;
	while(i < new_size)
	{
		_pairs.push_back(std::make_pair(_args[i], _args[i + 1]));
		i += 2;
	}
}

void	PmergeMeDeque::lets_ford_and_johnson(void)
{
	make_pairs();
	sort_within_pairs();
	sort_between_pairs();
	create_final_sequence();
	std::cout << "Before: ";
	for (size_t j = 0; j < _args.size(); j++)
		std::cout << _args[j] << " ";
	std::cout << std::endl;
	std::cout << "After:  ";
	for (size_t i = 0; i < _sorted.size(); i++)
		std::cout << _sorted[i] << " ";
	std::cout << std::endl;
}

#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}
PmergeMe::PmergeMe(int ac, char **av) {
	(void)ac;
	(void)av;
	// Constructor implementation
}
PmergeMe::PmergeMe(const PmergeMe &src) {}
PmergeMe &PmergeMe::operator=(const PmergeMe &src) {
	if (this != &src) {
		// Copy assignment operator implementation
	}
	return *this;
}
PmergeMe::~PmergeMe(void) {}

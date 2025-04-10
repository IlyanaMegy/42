#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>

class PmergeMe {
	private:
		
	public:
		PmergeMe(void);
		PmergeMe(int ac, char **av);
		PmergeMe(const PmergeMe &src);
		PmergeMe &operator=(const PmergeMe &src);
		~PmergeMe(void);

};

#endif

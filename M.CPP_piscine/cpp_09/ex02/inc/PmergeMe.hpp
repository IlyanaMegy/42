#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <sstream>

class PmergeMe {
    public:
        PmergeMe(void);
        PmergeMe(const PmergeMe& src);
        PmergeMe& operator=(const PmergeMe& src);
        ~PmergeMe(void);

		void					parseIt(int ac, char **av);

        bool					isVectorSorted(void) const;
        bool					isListSorted(void) const;
        void					sortAndDisplay(void);

    private:
        std::vector<int>		_vec;
        std::list<int>			_list;

        int						toInt(const std::string &str);

        std::vector<int>		mergeSortedVectors(const std::vector<int> &left, const std::vector<int> &right);
        std::list<int>			mergeSortedLists(const std::list<int> &left, const std::list<int> &right);

        void					sortVectorWithFordJohnson(std::vector<int> &vec);
        void					sortListWithFordJohnson(std::list<int> &list);
        
        void					printIt(const std::string &message);
};

#endif

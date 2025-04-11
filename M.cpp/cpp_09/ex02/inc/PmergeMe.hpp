#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <sstream>

#include "style.hpp"

class PmergeMe {
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& src);
        PmergeMe& operator=(const PmergeMe& src);
        ~PmergeMe();

		void					parseIt(int ac, char **av);

        bool					isVectorSorted() const;
        bool					isListSorted() const;
        void					sortAndDisplay();

    private:
        std::vector<int>		_vec;
        std::list<int>			_list;

        int						toInt(const std::string &str);

        std::vector<int>		mergeSortedVectors(const std::vector<int> &left, const std::vector<int> &right);
        std::list<int>			mergeSortedLists(const std::list<int> &left, const std::list<int> &right);

        void					sortVectorWithMerge(std::vector<int> &vec);
        void					sortListWithMerge(std::list<int> &list);
        
        void					printIt(const std::string &message);
};

#endif

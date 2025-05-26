#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}
PmergeMe::PmergeMe(const PmergeMe &src) { *this = src; }
PmergeMe::~PmergeMe(void) {}
PmergeMe &PmergeMe::operator=(const PmergeMe &src) {
    if (this != &src) {
        _vec = src._vec;
        _list = src._list;
    }
    return *this;
}

int PmergeMe::toInt(const std::string &str) {
    std::stringstream ss(str);
    int num;
    if (!(ss >> num) || !(ss.eof()))
        throw std::runtime_error("Error: Invalid value.");
    else if (num < 0)
        throw std::runtime_error("Error: Negative numbers are not allowed.");
    return num;
}

void PmergeMe::parseIt(int ac, char **av) {
    std::set<int> noDuplicateNbrs;

    for (int i = 1; i < ac; i++) {
        int num = toInt(av[i]);
        if (!noDuplicateNbrs.insert(num).second)
            throw std::runtime_error("Error: Number is already in the list.");
        _vec.push_back(num);
    }

    if (_vec.empty())
        throw std::runtime_error("Error: No valid numbers provided.");
    _list.assign(_vec.begin(), _vec.end());
}

void PmergeMe::printIt(const std::string &msg) {
    std::cout << "############# " << msg << " #############" << std::endl;

    std::cout << "Vector: (" << _vec.size() << " elements)\n[ ";
    for (std::vector<int>::const_iterator it = _vec.begin(); it != _vec.end(); ++it)
        std::cout << *it << " ";
    std::cout << "]" << std::endl;

    std::cout << "List: (" << _list.size() << " elements)\n[ ";
    for (std::list<int>::const_iterator it = _list.begin(); it != _list.end(); ++it)
        std::cout << *it << " ";
    std::cout << "]" << std::endl << std::endl;
}

std::vector<int> PmergeMe::mergeSortedVectors(const std::vector<int> &left, const std::vector<int> &right) {
    std::vector<int> result;
    size_t i = 0, j = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j])
            result.push_back(left[i++]);
        else
            result.push_back(right[j++]);
    }

    while (i < left.size())
        result.push_back(left[i++]);
    while (j < right.size())
        result.push_back(right[j++]);

    return result;
}

std::list<int> PmergeMe::mergeSortedLists(const std::list<int> &left, const std::list<int> &right) {
    std::list<int> result;
    std::list<int>::const_iterator itLeft = left.begin();
    std::list<int>::const_iterator itRight = right.begin();

    while (itLeft != left.end() && itRight != right.end()) {
        if (*itLeft <= *itRight) {
            result.push_back(*itLeft);
            ++itLeft;
        } else {
            result.push_back(*itRight);
            ++itRight;
        }
    }

    while (itLeft != left.end()) {
        result.push_back(*itLeft);
        ++itLeft;
    }

    while (itRight != right.end()) {
        result.push_back(*itRight);
        ++itRight;
    }

    return result;
}

void PmergeMe::sortVectorWithFordJohnson(std::vector<int> &vec) {
    if (vec.size() <= 1)
        return;

    std::vector<int> bigOne;
    std::vector<int> smolOne;
    for (size_t i = 0; i + 1 < vec.size(); i+=2 ) {
        if (vec[i] > vec[i + 1])
            std::swap(vec[i], vec[i + 1]);
        bigOne.push_back(vec[i + 1]);
        smolOne.push_back(vec[i]);
    }
    if (vec.size() % 2 != 0)
        bigOne.push_back(vec.back());

    sortVectorWithFordJohnson(bigOne);

    for (size_t i = 0; i < smolOne.size(); ++i) {
        std::vector<int>::iterator pos = std::lower_bound(bigOne.begin(), bigOne.end(), smolOne[i]);
        bigOne.insert(pos, smolOne[i]);
    }
    vec = bigOne;
}

void PmergeMe::sortListWithFordJohnson(std::list<int> &list) {
    if (list.size() <= 1)
        return;

    std::list<int> bigOne;
    std::list<int> smolOne;
    std::list<int>::iterator it = list.begin();
    while (it != list.end()) {
        int first = *it;
        ++it;
        if (it != list.end()) {
            int second = *it;
            if (first > second)
                std::swap(first, second);
            bigOne.push_back(second);
            smolOne.push_back(first);
            ++it;
        } else
            bigOne.push_back(first);
    }

    sortListWithFordJohnson(bigOne);
    for (std::list<int>::iterator smolIt = smolOne.begin(); smolIt != smolOne.end(); ++smolIt) {
        std::list<int>::iterator pos = bigOne.begin();
        while (pos != bigOne.end() && *pos < *smolIt)
            ++pos;
        bigOne.insert(pos, *smolIt);
    }
    list = bigOne;
}

bool PmergeMe::isVectorSorted(void) const {
    for (std::vector<int>::const_iterator it = _vec.begin(), next = ++_vec.begin(); next != _vec.end(); ++it, ++next)
        if (*it > *next)
            return false;
    return true;
}

bool PmergeMe::isListSorted(void) const {
    for (std::list<int>::const_iterator it = _list.begin(), next = ++_list.begin(); next != _list.end(); ++it, ++next)
        if (*it > *next)
            return false;
    return true;
}

void PmergeMe::sortAndDisplay(void) {
    std::cout << "Before sorting:" << std::endl;
    printIt("Initial state");

    clock_t startVec = clock();
    sortVectorWithFordJohnson(_vec);
    clock_t endVec = clock();
    double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000;

    clock_t startList = clock();
    sortListWithFordJohnson(_list);
    clock_t endList = clock();
    double timeList = static_cast<double>(endList - startList) / CLOCKS_PER_SEC * 1000;

    std::cout << "After sorting:" << std::endl;
    printIt("Sorted state");

    if (isVectorSorted() && isListSorted())
        std::cout << "Both containers are sorted correctly." << std::endl;
    else
        std::cerr << "Error: Sorting failed!" << std::endl;

    std::cout << "Time to sort vector: " << timeVec << " ms" << std::endl;
    std::cout << "Time to sort list: " << timeList << " ms" << std::endl;
}

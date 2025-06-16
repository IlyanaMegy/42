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

// ------------------------------------ PARSING FUNCTIONS ------------------------------------

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

// ----------------------------- SORTING AND DISPLAY FUNCTIONS ----------------------------------

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

static size_t jacobsthal(size_t n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

static std::vector<size_t> jacobsthalOrder(size_t n) {
    std::vector<size_t> order;
    std::vector<size_t> jacobIndices;
    size_t idx = 3;
    size_t jac;
    while ((jac = jacobsthal(idx)) <= n) {
        jacobIndices.push_back(jac);
        idx++;
    }

    for (size_t i = 0; i < jacobIndices.size(); ++i)
        order.push_back(jacobIndices[i]);

    size_t last = 1;
    for (size_t i = 0; i < jacobIndices.size(); ++i) {
        size_t j = jacobIndices[i] - 1;
        while (j > last) {
            order.push_back(j);
            --j;
        }
        last = jacobIndices[i];
    }

    while (++last <= n)
        order.push_back(last);
    return order;
}

static size_t binary_search(const std::vector<int>& sorted, int value) {
    size_t left = 0, right = sorted.size();
    while (left < right) {
        size_t mid = left + (right - left) / 2;
        if (sorted[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
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

    if (!smolOne.empty()) {
        std::vector<int> sorted(bigOne);
        size_t first = 0;
        size_t pos = binary_search(sorted, smolOne[first]);
        sorted.insert(sorted.begin() + pos, smolOne[first]);

        std::vector<size_t> order = jacobsthalOrder(smolOne.size());
        for (size_t k = 0; k < order.size(); ++k) {
            size_t idx = order[k];
            if (idx == 0 || idx >= smolOne.size())
                continue;
            int to_insert = smolOne[idx];
            size_t pos = binary_search(sorted, to_insert);
            sorted.insert(sorted.begin() + pos, to_insert);
        }
        bigOne = sorted;
    }
    vec = bigOne;
}

// la recherche binaire n’est pas faisable car std::list ne permet pas l’accès direct aux éléments. 
// j’utilise donc une insertion séquentielle, ce qui est conforme à l’énoncé et à la correction officielle.
static std::list<int>::iterator list_nth(std::list<int>& lst, size_t n) {
    std::list<int>::iterator it = lst.begin();
    std::advance(it, n);
    return it;
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

   if (!smolOne.empty()) {
        std::list<int>::iterator pos = bigOne.begin();
        int first = *smolOne.begin();
        while (pos != bigOne.end() && *pos < first)
            ++pos;
        bigOne.insert(pos, first);

        std::vector<size_t> order = jacobsthalOrder(smolOne.size());
        for (size_t k = 0; k < order.size(); ++k) {
            size_t idx = order[k];
            if (idx == 0 || idx >= smolOne.size())
                continue;
            int to_insert = *list_nth(smolOne, idx);
            pos = bigOne.begin();
            while (pos != bigOne.end() && *pos < to_insert)
                ++pos;
            bigOne.insert(pos, to_insert);
        }
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

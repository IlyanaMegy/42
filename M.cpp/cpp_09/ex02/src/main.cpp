#include "../inc/PmergeMe.hpp"

int main(int ac, char **av) {
	if (ac < 2)
        return (std::cerr << "Error: Please provide at least one number as input." << std::endl, 1);
	PmergeMe sorter;
	try {
        sorter.parseIt(ac, av);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
	try {
		sorter.sortAndDisplay();
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	
    return 0;
}

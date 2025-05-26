#include "../inc/RPN.hpp"

int main(int ac, char **av) {

	if (ac != 2)
		return (std::cerr << "Error: please provide an argument" << std::endl, 1);
	try
	{
		RPN rpn(av[1]);
		std::cout << "Result: " << rpn.calculate() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	return 0;
}

#include "../inc/BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		return (std::cout << RED1 << "Usage: ./btc [file]" << RESET << std::endl, 1);

	try
	{
		BitcoinExchange exchange;
		exchange.readDB(av[1]);
		exchange.execute(av[1]);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}

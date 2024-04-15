
#include "../inc/AAnimal.hpp"

AAnimal::AAnimal(void): _type("default")
{
	std::cout << YELLOW << this->getType() << " AAnimal has been created." << RESET << std::endl;
}

AAnimal::AAnimal(AAnimal const &copy)
{
	std::cout << YELLOW << "AAnimal Copy constructor has been called." << RESET << std::endl;
	*this = copy;
}

AAnimal &AAnimal::operator=(AAnimal const &assign)
{
	std::cout << YELLOW << "AAnimal Assignation operator has been called." << RESET << std::endl;
	if (this != &assign)
		this->_type = assign._type;
	return (*this);
}

AAnimal::~AAnimal(void)
{
	std::cout << YELLOW << this->getType() << " AAnimal has been killed." << RESET << std::endl;
}

std::string AAnimal::getType(void) const
{
	return (this->_type);
}

void AAnimal::makeSound(void) const
{
	std::cout << YELLOW << this->getType() << " AAnimal doesn't make any sound." << RESET << std::endl;
}

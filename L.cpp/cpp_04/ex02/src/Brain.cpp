
#include "../inc/Brain.hpp"

Brain::Brain(void)
{
	std::cout << GREEN << "adding brain..." << RESET << std::endl;
}

Brain::Brain(Brain const &copy)
{
	std::cout << GREEN << "copying brain..." << RESET << std::endl;
	*this = copy;
}

Brain &Brain::operator=(Brain const &assign)
{
	std::cout << GREEN << "assigning brain..." << RESET << std::endl;
	if (this != &assign)
		for (int i = 0; i < 100; i++)
			if (assign._ideas[i].length() > 0)
				this->_ideas[i].assign(assign._ideas[i]);
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << GREEN << "removing brain..." << RESET << std::endl;
}

std::string Brain::getIdea(unsigned int idx) const
{
	if (idx > 99)
	{
		std::cout << GREEN << "Idea " << idx << " is out of range!" << RESET << std::endl;
		return ("");
	}
	return (this->_ideas[idx]);
}

void Brain::setIdea(unsigned int idx, std::string idea)
{
	if (idx > 99)
	{
		std::cout << GREEN << "Idea " << idx << " is out of range!" << RESET << std::endl;
		return ;
	}
	this->_ideas[idx] = idea;
}

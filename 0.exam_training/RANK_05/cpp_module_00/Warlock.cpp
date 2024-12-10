#include "Warlock.hpp"

Warlock::Warlock(){}
Warlock::Warlock(Warlock const &src){*this = src; }
Warlock &Warlock::operator=(Warlock const &src)
{
	this->_name = src.getName();
	this->_title = src.getTitle();
	return *this;
}

Warlock::Warlock(std::string n, std::string t): _name(n)
{
	setTitle(t);
	std::cout << this->getName() << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << this->getName() << ": My job is done!" << std::endl;
}

std::string Warlock::getName() const{return _name; }
std::string Warlock::getTitle() const{return _title; }
void Warlock::setTitle(const std::string &t){this->_title = t; }
void Warlock::introduce() const
{
	std::cout << this->getName() <<  ": I am " << this->getName() << ", " <<this->getTitle() << "!" << std::endl;
}

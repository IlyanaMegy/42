#include "ASpell.hpp"

ASpell::ASpell(){}
ASpell::~ASpell(){}
ASpell::ASpell(std::string n, std::string e): _name(n), _effects(e){}
ASpell::ASpell(ASpell const &src){*this = src; }
ASpell &ASpell::operator=(ASpell const &src)
{
	_name = src.getName();
	_effects = src.getEffects();
	return *this;
}

std::string ASpell::getName() const{return _name; }
std::string ASpell::getEffects() const{return _effects; }
void ASpell::launch(const ATarget &target) const
{
	target.getHitByASpell(*this);
}

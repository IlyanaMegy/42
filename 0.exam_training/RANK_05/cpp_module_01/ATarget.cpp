#include "ATarget.hpp"

ATarget::ATarget(){}
ATarget::ATarget(std::string t): _type(t){}
ATarget::ATarget(ATarget const &src){*this = src; }
ATarget &ATarget::operator=(ATarget const &src){_type = src.getType(); return *this; }
ATarget::~ATarget(){}

std::string ATarget::getType() const{return _type; }
void ATarget::getHitByASpell(const ASpell &spell) const
{
	std::cout << this->getType() << " has been " << spell.getEffects() << std::endl;
}

#pragma once
#include "ASpell.hpp"

class ASpell;
class ATarget
{
	protected:
		std::string _type;
		ATarget();
	public:
		ATarget(std::string t);
		ATarget(ATarget const &src);
		ATarget &operator=(ATarget const &src);
		virtual ~ATarget();
		virtual ATarget *clone() const = 0;

		std::string getType() const;
		void getHitByASpell(const ASpell &spell) const;
};

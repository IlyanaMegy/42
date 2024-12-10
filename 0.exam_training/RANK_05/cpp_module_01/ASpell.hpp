#pragma once
#include <iostream>
#include "ATarget.hpp"

class ATarget;
class ASpell
{
	protected:
		std::string _name;
		std::string _effects;
		ASpell();
	public:
		ASpell(std::string n, std::string e);
		virtual ~ASpell();
		ASpell(ASpell const &src);
		ASpell &operator=(ASpell const &src);
		virtual ASpell *clone() const = 0;

		std::string getName() const;
		std::string getEffects() const;
		void launch(const ATarget &target) const;
};

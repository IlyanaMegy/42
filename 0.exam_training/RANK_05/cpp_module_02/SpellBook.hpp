#pragma once
#include <map>
#include "ASpell.hpp"
#include <string>

class SpellBook
{
	protected:
		SpellBook(SpellBook const &src);
		SpellBook &operator=(SpellBook const &src);
		std::map<std::string, ASpell *> _arr_spell;
	public:
		SpellBook();
		~SpellBook();
		void learnSpell(ASpell *);
		void forgetSpell(std::string const &);
		ASpell *createSpell(std::string const &);
};

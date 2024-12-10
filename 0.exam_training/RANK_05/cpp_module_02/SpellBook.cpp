#include "SpellBook.hpp"

SpellBook::SpellBook(){}
SpellBook::~SpellBook()
{
	std::map<std::string, ASpell *>::iterator it_begin = _arr_spell.begin();
	std::map<std::string, ASpell *>::iterator it_end = _arr_spell.end();
	while (it_begin != it_end)
	{
		delete it_begin->second;
		it_begin++;
	}
	this->_arr_spell.clear();
}

void SpellBook::learnSpell(ASpell *spell)
{
	if (spell)
		_arr_spell.insert(std::pair<std::string, ASpell *>(spell->getName(), spell->clone()));
}

void SpellBook::forgetSpell(std::string const &spell)
{
	std::map<std::string, ASpell *>::iterator it = _arr_spell.find(spell);
	if (it != _arr_spell.end())
	{
		delete it->second;
		_arr_spell.erase(spell);
	}
}

ASpell *SpellBook::createSpell(std::string const &spell)
{
	std::map<std::string, ASpell *>::iterator it = _arr_spell.find(spell);
	if (it != _arr_spell.end())
		return _arr_spell[spell];
	return NULL;
}

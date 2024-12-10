#include <iostream>
#include "ASpell.hpp"
#include "SpellBook.hpp"
#include <map>

class ASpell;
class ATarget;
class Warlock
{
	private:
		std::string _name;
		std::string _title;
		SpellBook _spellbook;
		Warlock();
		Warlock(Warlock const &src);
		Warlock &operator=(Warlock const &src);
	public:
		Warlock(std::string n, std::string t);
		~Warlock();

		std::string getName() const;
		std::string getTitle() const;
		void setTitle(const std::string &t);
		void introduce() const;

		void learnSpell(ASpell *spell);
		void forgetSpell(std::string spell);
		void launchSpell(std::string spell, const ATarget &target);
};

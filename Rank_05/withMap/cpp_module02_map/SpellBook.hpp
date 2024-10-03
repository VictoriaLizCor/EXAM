#pragma once

# include <string>
# include <iostream>
# include <map>
# include "ASpell.hpp"

typedef std::map<std::string, ASpell*>::iterator ite;
class SpellBook
{
	private:
		std::map<std::string, ASpell*> _spells;

		SpellBook(SpellBook const& rhs);
		SpellBook& operator=(SpellBook const& rhs);

	public:
		SpellBook();
		~SpellBook();
		void learnSpell(ASpell * spell);
		void forgetSpell(std::string spellName);
		ASpell* createSpell(std::string const& toCreate);
};
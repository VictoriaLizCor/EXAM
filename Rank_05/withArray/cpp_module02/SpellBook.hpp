#pragma once

#include "ASpell.hpp"

#ifndef DEBUG
 #define DEBUG 0
#endif

class SpellBook
{
	private:
		static size_t const _sizeSpells = 5;
		ASpell* spells[_sizeSpells];
		SpellBook(SpellBook const &other);
		SpellBook &operator=(SpellBook const &other);

	public:
		SpellBook();
		~SpellBook();

		void learnSpell(ASpell* toLearn);
		void forgetSpell(std::string const& toForget);
		ASpell* createSpell(std::string const& toCreate);
		void checkSpells(void);
};
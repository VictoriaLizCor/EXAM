
#include "SpellBook.hpp"

SpellBook::SpellBook(SpellBook const& rhs){(void)rhs;}

SpellBook& SpellBook::operator=(SpellBook const& rhs)
{
	(void)rhs;
	return *this;
}


SpellBook::SpellBook()
{
}

SpellBook::~SpellBook()
{
	for (std::map<std::string, ASpell*>::iterator it = _spells.begin(); it != _spells.end(); ++it) {
		delete it->second;
	}
	_spells.clear();
}

void SpellBook::learnSpell(ASpell* spell)
{
	if (spell)
	{
		if (_spells.find(spell->getName()) == _spells.end())
			_spells[spell->getName()] = spell->clone();
		delete spell;
	}
}

void SpellBook::forgetSpell(std::string toForget)
{
	std::map<std::string, ASpell*>::iterator it = _spells.find(toForget);
	if (it != _spells.end())
	{
		delete it->second;
		_spells.erase(it);
	}
}

ASpell* SpellBook::createSpell(std::string const& toCreate)
{
	ASpell* tmp = NULL;
	if (_spells.find(toCreate) != _spells.end())
		tmp = _spells[toCreate];
	return (tmp);
}
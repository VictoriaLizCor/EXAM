#include "Warlock.hpp"

Warlock::Warlock(){}
		
Warlock::Warlock(Warlock const& rhs){(void)rhs;}
Warlock& Warlock::operator=(Warlock const& rhs)
{
	(void)rhs;
	return *this;
}

Warlock::Warlock(std::string const& name, std::string const& title):
_name(name), _title(title)
{
	std::cout << _name << ": " << "This looks like another boring day." << std::endl;
	typedef std::map<std::string, ASpell*>::iterator ite;
	for (ite it = _spells.begin(); it != _spells.end(); ++it)
		delete it->second;
	_spells.clear();
}

Warlock::~Warlock()
{
	std::cout << _name << ": " << "My job here is done!" << std::endl;
}

std::string const& Warlock::getName() const
{
	return _name;
}
std::string const& Warlock::getTitle() const
{
	return _title;
}
void Warlock::introduce() const
{
	std::cout << _name << ": " << "I am " << _name ;
	std::cout << ", " << _title << "!" << std::endl;
}

void Warlock::setTitle(std::string const& title)
{
	_title = title;
}


void Warlock::learnSpell(ASpell* spell)
{
	if (spell)
	{
		if (_spells.find(spell->getName()) == _spells.end())
			_spells[spell->getName()] = spell->clone();
		delete spell;
	}
}

void Warlock::forgetSpell(std::string SpellName)
{
	ite it = _spells.find(SpellName);
	if (it != _spells.end())
	{
		delete it->second;
		_spells.erase(_spells.find(SpellName));
	}
}

void Warlock::launchSpell(std::string SpellName, ATarget const & target)
{
	if (_spells.find(SpellName) != _spells.end())
		_spells[SpellName]->launch(target);
}
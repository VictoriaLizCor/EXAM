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
	_spellBook.learnSpell(spell);
}

void Warlock::forgetSpell(std::string spellName)
{
	_spellBook.forgetSpell(spellName);
}

void Warlock::launchSpell(std::string toLaunch, ATarget const & target)
{
	if(_spellBook.createSpell(toLaunch))
		_spellBook.createSpell(toLaunch)->launch(target);
}
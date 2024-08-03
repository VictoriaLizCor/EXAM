#include "Warlock.hpp"
#include <string>

Warlock::Warlock(std::string const& name, std::string const& title):
_name(name)
{
	setTitle(title);
	std::cout << getName() << ": "
	<< "This looks like another boring day."
	<< std::endl;
	
}

Warlock::Warlock()
{
}

Warlock & Warlock::operator=(Warlock const & rhs)
{
	this->_name = rhs._name;
	this->_title = rhs._title;
	return (*this);
}

Warlock::Warlock(Warlock const & obj)
{
	*this = obj;
}

Warlock::~Warlock()
{
	std::cout << this->_name << ": My job here is done!" << std::endl;
}



void Warlock::setTitle(std::string const& title)
{
	_title = title;
}

std::string const& Warlock::getName() const
{
	return (_name);
}

std::string const& Warlock::getTitle() const
{
	return (_title);
}


void Warlock::introduce(void) const
{
	std::cout << getName() << ": "
	<< "I am " << getName()
	<< ", " << getTitle() << "!"
	<< std::endl;
}

void Warlock::learnSpell(ASpell* toLearn)
{
	spells.learnSpell(toLearn);
	if (DEBUG)
		spells.checkSpells();
}

void Warlock::forgetSpell(std::string toForget)
{
	spells.forgetSpell(toForget);
}

void Warlock::launchSpell(std::string toLaunch, ATarget const& target)
{
	ASpell* tmp = spells.createSpell(toLaunch);

	if (tmp)
		tmp->launch(target);
	if (DEBUG && tmp == NULL)
		std::cout << "NULL CREATED\n";
}

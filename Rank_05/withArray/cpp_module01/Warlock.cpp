#include "Warlock.hpp"
#include <string>

Warlock::Warlock(std::string const& name, std::string const& title):
_name(name)
{
	setTitle(title);
	std::cout << getName() << ": "
	<< "This looks like another boring day."
	<< std::endl;
	for (size_t i = 0; i < _sizeSpells; ++i)
		spells[i] = NULL;
	// checkSpells();
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
	for (size_t i = 0; i < _sizeSpells; ++i)
	{
		if (spells[i])
		{
			if (DEBUG)
			{
				std::cout << spells[i]->getName()
				<< " deleted" << std::endl;
			}
			delete spells[i];
		}
		spells[i] = NULL;
	}
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
	if (toLearn)
	{
		for (size_t i = 0; i < _sizeSpells; ++i)
		{
			if (spells[i] && toLearn->getName() == spells[i]->getName())
			{
				if (spells[i] != toLearn)
					delete toLearn;
				return ;
			}
			spells[i] = toLearn;
			return ;
		}
	}
	// if (DEBUG)
	// 	checkSpells();
}

void Warlock::forgetSpell(std::string toForget)
{
	for (size_t i = 0; i < _sizeSpells; ++i)
	{
		if (spells[i] != NULL && toForget == spells[i]->getName())
		{
			delete spells[i];
			spells[i] = NULL;
			return ;
		}
	}
}

void Warlock::launchSpell(std::string toLaunch, ATarget const& target)
{
	for (size_t i = 0; i < _sizeSpells; ++i)
	{
		if (spells[i] && toLaunch == spells[i]->getName())
		{
			spells[i]->launch(target);
			return ;
		}
	}
}

// void Warlock::checkSpells(void)
// {
// 	if (DEBUG)
// 	{
// 		for (size_t i = 0; i < _sizeSpells; ++i)
// 		{
// 			std::cout << i << "-";
// 			if (spells[i])
// 				std::cout << spells[i]->getName() << " ";
// 			else
// 				std::cout << "NULL" << " ";
// 		}
// 		std::cout << std::endl;
// 	}
// }

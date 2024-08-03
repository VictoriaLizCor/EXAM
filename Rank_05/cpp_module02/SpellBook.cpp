#include "SpellBook.hpp"


SpellBook::SpellBook() {
	for (size_t i = 0; i < _sizeSpells; ++i)
		spells[i] = NULL;
	if (DEBUG)
		checkSpells();
}

SpellBook::~SpellBook()
{
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

void SpellBook::learnSpell(ASpell* toLearn)
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
			if (spells[i] == NULL)
			{
				spells[i] = toLearn->clone();
				delete toLearn;
				return ;
			}
		}
	}
	if (DEBUG)
		checkSpells();
}

void SpellBook::forgetSpell(std::string const &toForget)
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

ASpell* SpellBook::createSpell(std::string const &toCreate)
{
	for (size_t i = 0; i < _sizeSpells; ++i)
	{
		if (spells[i] && toCreate == spells[i]->getName())
		{
			return (spells[i]);
		}
	}
	return (NULL);
}

void SpellBook::checkSpells(void)
{
	if (DEBUG)
	{
		std::cout << "SPELLS: ";
		for (size_t i = 0; i < _sizeSpells; ++i)
		{
			std::cout << i << "-";
			if (spells[i])
				std::cout << spells[i]->getName() << " ";
			else
				std::cout << "NULL" << " ";
		}
		std::cout << std::endl;
	}
}

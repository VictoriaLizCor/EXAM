#pragma once

# include <string>
# include <iostream>
# include <map>
# include "ASpell.hpp"
# include "SpellBook.hpp"


class Warlock
{
	private:
		std::string _name;
		std::string _title;
		SpellBook _spellBook;

		Warlock();
		Warlock(Warlock const& rhs);
		Warlock& operator=(Warlock const& rhs);

	public:
		Warlock(std::string const& name, std::string const& title);
		~Warlock();

		std::string const& getName() const;
		std::string const& getTitle() const;
		void introduce() const;
		void setTitle(std::string const& title);
		void learnSpell(ASpell * spell);
		void forgetSpell(std::string spellName);
		void launchSpell(std::string toLaunch, ATarget const& target);
};


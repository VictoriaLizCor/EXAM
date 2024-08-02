#ifndef WARLOCK_HPP
 #define  WARLOCK_HPP

#include <iostream>
#include <string>
#include "ASpell.hpp"

#ifndef DEBUG
 #define DEBUG 0
#endif


class Warlock {

	private :
		std::string _name;
		std::string _title;
		static size_t const _sizeSpells = 5;
		ASpell* spells[_sizeSpells];

		Warlock();
		Warlock& operator=(Warlock const& rhs);
		Warlock(Warlock const& obj);

	public :
		Warlock(std::string const& name, std::string const& title);
		~Warlock();
		std::string const& getName() const;
		std::string const& getTitle() const;
		void setTitle(std::string const& str);
		void introduce() const;
		void learnSpell(ASpell* spell);
		void forgetSpell(std::string SpellName);
		void launchSpell(std::string toLaunch, ATarget const& target);
		// void checkSpells(void);
};

#endif

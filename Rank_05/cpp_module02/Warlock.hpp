#ifndef WARLOCK_HPP
 #define  WARLOCK_HPP

#include <iostream>
#include <string>
#include "ASpell.hpp"
#include "SpellBook.hpp"
#ifndef DEBUG
 #define DEBUG 0
#endif


class Warlock {

	private :
		std::string _name;
		std::string _title;
		SpellBook spells;

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
};

#endif

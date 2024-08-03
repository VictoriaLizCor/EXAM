#ifndef A_SPELL_HPP
 #define  A_SPELL_HPP

#include <iostream>
#include <string>
#include "ATarget.hpp"

class ATarget;
class ASpell
{
	public:
		ASpell(std::string const& name, std::string const& effects);
		ASpell(ASpell const& rhs);
		ASpell& operator=(ASpell const& rhs);
		virtual ~ASpell();
		std::string const& getName() const;
		std::string const& getEffects() const;
		virtual ASpell* clone() const= 0;
		void launch(ATarget const& target) const;
	private:
		std::string _name;
		std::string _effects;

};
#endif

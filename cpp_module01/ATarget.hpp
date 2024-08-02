#ifndef A_TARGET_HPP
 #define  A_TARGET_HPP

#include <iostream>
#include <string>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
	public:
		ATarget(std::string const& type);
		ATarget(ATarget const& rhs);
		ATarget& operator=(ATarget const& rhs);
		virtual ~ATarget();

		std::string const& getType() const;
		virtual ATarget* clone() const= 0;
		void getHitBySpell(ASpell const& spell) const;
	private:
		std::string _type;
		std::string _effects;


};
#endif

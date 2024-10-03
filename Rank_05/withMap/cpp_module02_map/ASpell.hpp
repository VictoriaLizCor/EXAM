#pragma once
# include <string>
# include <iostream>
#include "ATarget.hpp"

class ATarget;
class ASpell
{
	private:
		std::string _name;
		std::string _effects;

		ASpell();
		ASpell(ASpell const& rhs);
		ASpell& operator=(ASpell const& rhs);

	public:
		ASpell(std::string const& name, std::string const& title);
		virtual ~ASpell();
		std::string const& getName() const;
		std::string const& getEffects() const;
		virtual ASpell* clone() const = 0;
		void launch(ATarget const& target) const;
};
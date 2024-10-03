#pragma once
# include <string>
# include <iostream>

class ASpell;
class ATarget
{
	private:
		std::string _type;

		ATarget();
		ATarget(ATarget const& rhs);
		ATarget& operator=(ATarget const& rhs);

	public:
		ATarget(std::string const& type);
		virtual ~ATarget();
		std::string const& getType() const;
		virtual ATarget* clone() const = 0;
		void getHitBySpell(ASpell const& spell) const;

};
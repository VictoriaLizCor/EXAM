#include "ASpell.hpp"
#include "ATarget.hpp"

ASpell::ASpell(){}
		
ASpell::ASpell(ASpell const& rhs){(void)rhs;}

ASpell& ASpell::operator=(ASpell const& rhs)
{
	(void)rhs;
	return *this;
}

ASpell::ASpell(std::string const& name, std::string const& effects):
_name(name), _effects(effects)
{
	// std::cout << _name << ": " << "This looks like another boring day." << std::endl;
}

ASpell::~ASpell()
{
	// std::cout << _name << ": " << "My job here is done!" << std::endl;
}

std::string const& ASpell::getName() const
{
	return _name;
}
std::string const& ASpell::getEffects() const
{
	return _effects;
}

void ASpell::launch(ATarget const& target) const
{
	target.getHitBySpell(*this);
}

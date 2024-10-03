#include "ATarget.hpp"
#include "ASpell.hpp"

ATarget::ATarget(){}
		
ATarget::ATarget(ATarget const& rhs){(void)rhs;}

ATarget& ATarget::operator=(ATarget const& rhs)
{
	(void)rhs;
	return *this;
}

ATarget::ATarget(std::string const& type):
_type(type)
{
	// std::cout << _name << ": " << "This looks like another boring day." << std::endl;
}

ATarget::~ATarget()
{
	// std::cout << _name << ": " << "My job here is done!" << std::endl;
}

std::string const& ATarget::getType() const
{
	return _type;
}

void ATarget::getHitBySpell(ASpell const& spell) const
{
	std::cout << _type << " has been " << spell.getEffects() << "!" << std::endl;
}

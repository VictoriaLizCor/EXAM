#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(TargetGenerator const& rhs){(void)rhs;}

TargetGenerator& TargetGenerator::operator=(TargetGenerator const& rhs)
{
	(void)rhs;
	return *this;
}

TargetGenerator::TargetGenerator()
{}

TargetGenerator::~TargetGenerator()
{}

void TargetGenerator::learnTargetType(ATarget* target)
{
	if (target)
	{
		if (_target.find(target->getType()) == _target.end())
			_target[target->getType()] = target;
	}
}

void TargetGenerator::forgetTargetType(std::string const & target)
{
	if (_target.find(target) != _target.end())
		_target.erase(_target.find(target));
}

ATarget* TargetGenerator::createTarget(std::string const &target)
{
	ATarget* tmp = NULL;
	if (_target.find(target) != _target.end())
		tmp = _target[target];
	return (tmp);
}
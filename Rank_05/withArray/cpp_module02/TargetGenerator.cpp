#include "TargetGenerator.hpp"
#include <typeinfo>

static void checkType(ATarget* target)
{
	// if (typeid(*target) == typeid(ATarget*))
	// 	std::cout << typeid(*target).name() << " is Pointer\n";
	// if (typeid(*target) == typeid(ATarget))
	// 	std::cout << typeid(*target).name() << " is Reference\n";
	std::cout << typeid(&target).name() << "\n";
	std::cout << typeid(*target).name() << "\n";
	std::cout << (typeid(*target)==typeid(ATarget)) << "\n";
}

TargetGenerator::TargetGenerator()
{
	for (size_t i = 0; i < _sizeTargets; ++i)
		Targets[i] = NULL;
	if (DEBUG)
		checkTargets();
}

TargetGenerator::~TargetGenerator()
{
	// for (size_t i = 0; i < _sizeTargets; ++i)
	// {
	// 	if (Targets[i])
	// 	{
	// 		if (DEBUG)
	// 		{
	// 			std::cout << Targets[i]->getType()
	// 			<< " deleted" << std::endl;
	// 		}
	// 		delete Targets[i];
	// 	}
	// 	Targets[i] = NULL;
	// }
	if (DEBUG)
		checkTargets();
}

void TargetGenerator::learnTargetType(ATarget* toLearn)
{
	if (toLearn)
	{
		checkType(toLearn);
		for (size_t i = 0; i < _sizeTargets; ++i)
		{
			// if (Targets[i] && toLearn->getType() == Targets[i]->getType())
			// {
			// 	// if (Targets[i] != toLearn)
			// 	// 	delete toLearn;/*  */
			// 	return ;
			// }
			if (Targets[i] == NULL)
			{
				Targets[i] = toLearn;
				// delete toLearn;
				return ;
			}
		}
	}
	if (DEBUG)
		checkTargets();
}

void TargetGenerator::forgetTargetType(const std::string &toForget)
{
	for (size_t i = 0; i < _sizeTargets; ++i)
	{
		if (Targets[i] != NULL && toForget == Targets[i]->getType())
		{
			// delete Targets[i];
			Targets[i] = NULL;
			return ;
		}
	}
}

ATarget* TargetGenerator::createTarget(const std::string &toCreate)
{
	for (size_t i = 0; i < _sizeTargets; ++i)
	{
		if (Targets[i] && toCreate == Targets[i]->getType())
		{
			return (Targets[i]);
		}
	}
	return (NULL);
}

void TargetGenerator::checkTargets(void)
{
	if (DEBUG)
	{
		std::cout << "TARGETS: ";
		for (size_t i = 0; i < _sizeTargets; ++i)
		{
			std::cout << i << "-";
			if (Targets[i])
				std::cout << typeid(*Targets[i]).name() << " ";
			else
				std::cout << "NULL" << " ";
		}
		std::cout << std::endl;
	}
}

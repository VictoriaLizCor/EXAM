#include "TargetGenerator.hpp"

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
		for (size_t i = 0; i < _sizeTargets; ++i)
		{
			if (Targets[i] && toLearn->getType() == Targets[i]->getType())
			{
				// if (Targets[i] != toLearn)
				// 	delete toLearn;/*  */
				return ;
			}
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
				std::cout << Targets[i]->getType() << " ";
			else
				std::cout << "NULL" << " ";
		}
		std::cout << std::endl;
	}
}

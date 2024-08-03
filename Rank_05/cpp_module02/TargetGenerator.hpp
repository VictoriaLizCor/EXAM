#pragma once

#include "ATarget.hpp"

#ifndef DEBUG
 #define DEBUG 0
#endif

class TargetGenerator
{
	private:
		static size_t const _sizeTargets = 5;
		ATarget* Targets[_sizeTargets];

		TargetGenerator(TargetGenerator const& other);
		TargetGenerator &operator=(TargetGenerator const& other);

	public:
		TargetGenerator();
		~TargetGenerator();

		void learnTargetType(ATarget* toLearn);
		void forgetTargetType(std::string const& toForget);
		ATarget* createTarget(std::string const& toCreate);
		void checkTargets(void);
};
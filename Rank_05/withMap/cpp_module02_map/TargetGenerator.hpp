#pragma once
# include <string>
# include <iostream>
# include <map>
# include "ATarget.hpp"

class TargetGenerator
{
	private:;
		std::map < std::string, ATarget*> _target;

		TargetGenerator(TargetGenerator const &other);
		TargetGenerator &operator=(TargetGenerator const &other);

	public:
		TargetGenerator();
		~TargetGenerator();

		void learnTargetType(ATarget*);
		void forgetTargetType(std::string const &type);
		ATarget* createTarget(std::string const &type);
};
#include "ATarget.hpp"
#pragma once
#include <map>

class TargetGenerator
{
	protected:
		TargetGenerator(TargetGenerator const &src);
		TargetGenerator &operator=(TargetGenerator const &src);
		std::map<std::string, ATarget *> _target;
	public:
		TargetGenerator();
		~TargetGenerator();
		void learnTargetType(ATarget *);
		void forgetTargetType(std::string const &);
		ATarget *createTarget(std::string const &);
};

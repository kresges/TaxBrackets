// taxBrackets
#include "taxBrackets.h"

taxBrackets::taxBrackets(const std::string & instanceName)
{
	instanceName_ = instanceName;
}

taxBrackets::~taxBrackets(){};

std::string taxBrackets::getInstanceName()
{
	return instanceName_;
};


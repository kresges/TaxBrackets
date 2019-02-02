#ifndef TAXBRACKETS_H 
#define TAXBRACKETS_H

#include<iostream>

class taxBrackets 
{
public:

	taxBrackets(const std::string & instanceName);

	~taxBrackets();

	// Methods
	std::string getInstanceName();

private:
	std::string instanceName_;
};

#endif
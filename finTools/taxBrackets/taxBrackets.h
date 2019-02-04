#ifndef TAXBRACKETS_H 
#define TAXBRACKETS_H

#include <iostream>
#include <sstream>
#include <map>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

using namespace boost::property_tree;

class taxBrackets 
{
public:

	taxBrackets(const std::string & instanceName);

	~taxBrackets();

	// Methods
	std::string getInstanceName();
	double getTaxLiability(const double & income);

private:
	//Methods
	void parseTaxInformation_();
	void parseTaxBrackets_(ptree & input);

	// Variables
	std::string instanceName_;
	double standardDeduction_;
	std::map<double,double> brackets_;

};

#endif
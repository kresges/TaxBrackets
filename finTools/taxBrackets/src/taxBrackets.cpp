// taxBrackets
#include "taxBrackets/taxBrackets.h"

taxBrackets::taxBrackets(const std::string & instanceName)
{
	instanceName_ = instanceName;
	parseTaxInformation_();
}

taxBrackets::~taxBrackets(){};

std::string taxBrackets::getInstanceName()
{
	return instanceName_;
};

// Public Methods
double taxBrackets::getTaxLiability(const double & income)
{
	double remaining = income - standardDeduction_;
	double liability = 0;

	for (auto it = brackets_.rbegin(); it != brackets_.rend(); ++it)
	{
		//std::cout << it->first << " : " << it->second << std::endl;
		if(remaining >= it->first)
		{
			liability += (remaining - it->first) * it->second;
			//std::cout << "OWE: " << (remaining - it->first) * it->second << " : " << remaining - it->first << std::endl;
			remaining = it->first;
		}
		else if(remaining < it->first)
		{
			//std::cout << "SKIPPED: " << it->first << std::endl;
			continue;
		}
	}
	return liability;
}


//  Private Methods
void taxBrackets::parseTaxInformation_()
{
	ptree input;
	json_parser::read_json("files/taxBrackets_2018.json", input);

	for( auto & item : input )
	{
		if( item.first == "standard deduction" )
		{
			standardDeduction_ = item.second.get_value<double>();
		}
		else if( item.first == "brackets" )
		{
			parseTaxBrackets_(item.second);
		}
	}
}

void taxBrackets::parseTaxBrackets_(ptree & input)
{
	double n;

	for( auto & bracket : input )
	{
		// Convert string to double
		std::istringstream ss( bracket.first );
		ss >> n;
		brackets_[n] = (double) bracket.second.get_value<double>();
		//std::cout << "Cut Off: " << bracket.first << " Tax Rate: " << bracket.second.data() << std::endl;
	}
}

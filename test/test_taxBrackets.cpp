#include <iostream>
#include "gtest/gtest.h"

#include "taxBrackets.h"

class taxBracketTest : public ::testing::Test
{
protected:
	taxBrackets * tb = new taxBrackets("TaxBrackets_2018");
	std::map<double, double> incomes = {
		{12100, 10},
		{13000, 100},
		{112000, 18289.48},
		{1012000, 335689.48}
	};
};

TEST_F(taxBracketTest, LoadAndComputeTaxLiability)
{
	for( auto & input : incomes )
	{
		EXPECT_DOUBLE_EQ(tb->getTaxLiability(input.first), input.second);
	}
}


#include "main.h"

int main(int argc, char *argv[])
{
    std::cout << "Hello World!" << std::endl;
    std::cout << "Hello Travis CI!" << std::endl;

    taxBrackets * tb = new taxBrackets("TaxBrackets_2018");

    std::cout << tb->getInstanceName() << std::endl;
    double income = 100000.00;
    std::cout << "Tax Liability: " << tb->getTaxLiability(income) << " on " << income << "$" << std::endl;
    return 0;
}
#include "Treasury.hpp"

void Treasury::calculateRevenue(int titleLevel, int justiceLevel, int nobleCount,
                      int clergyCount, int merchantCount, double publicWorks) {

    double temp = 150 - mSalesTax - mCustomsTax - mIncomeTax;
    if (temp < 1.0) {
        temp = 1.0;
    }
    temp /= 100.0;

    mJusticeRevenue = (justiceLevel * 300 - 500) * titleLevel;

    mCustomsTaxRevenue = nobleCount * 180 + clergyCount * 75 + merchantCount * 20 * (int)temp;
    mCustomsTaxRevenue += (int)(publicWorks * 100.0);
    mCustomsTaxRevenue = (int)((mCustomsTax / 100.0) * mCustomsTaxRevenue);

    mSalesTaxRevenue = nobleCount * 50 + merchantCount * 25 + (int)publicWorks * 10;
    mSalesTaxRevenue *= (int)temp * (5 - justiceLevel) * mSalesTax;
    mSalesTaxRevenue /= 200;

    mIncomeTaxRevenue = nobleCount * 250 + (int)publicWorks * 20 + (10 * justiceLevel * nobleCount * (int)temp);
    mIncomeTaxRevenue *= mIncomeTax;
    mIncomeTaxRevenue /= 100;

    int totalRevs = mJusticeRevenue + mCustomsTaxRevenue + mSalesTaxRevenue + mIncomeTaxRevenue;

    std::cout << "State revenues " << totalRevs << " gold florins\n";
    std::cout << "Income Tax: " << mIncomeTaxRevenue << "\n";
    std::cout << "Sales Tax: " << mSalesTaxRevenue << "\n";
    std::cout << "Customs Duty: " << mCustomsTaxRevenue << "\n";
    std::cout << "Justice: " << mJusticeRevenue << "\n";

}
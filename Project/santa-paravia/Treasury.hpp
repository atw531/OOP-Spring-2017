#ifndef SANTA_PARAVIA_TREASURY_HPP
#define SANTA_PARAVIA_TREASURY_HPP

#include <iostream>

class Treasury {
public:
    Treasury()
            : mTotal(1000), isBankrupt(false), mCustomsTax(25), mSalesTax(10), mIncomeTax(5) {

    }

    void calculateRevenue(int titleLevel, int justiceLevel, int nobleCount,
                          int clergyCount, int merchantCount, double publicWorks);

    int getTotal() { return mTotal; }

private:
    int mTotal;
    bool isBankrupt;

    int mCustomsTax;
    int mCustomsTaxRevenue;

    int mJusticeRevenue;
    int mMarketRevenue;
    int mMillRevenue;

    int mSalesTax;
    int mSalesTaxRevenue;

    int mIncomeTax;
    int mIncomeTaxRevenue;

};

#endif //SANTA_PARAVIA_TREASURY_HPP

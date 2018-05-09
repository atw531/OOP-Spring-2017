#include "City.hpp"

void City::buyCathedral() {
    mCathedral.Count += 1;
    RandomGenerator generator;
    mClergy.Count += generator.withinRange(1, 6);
    mTotalTreasury -= 5000;
    mPublicWorks += 1.0;
}

void City::setGrain(int total) {
    if (total >= 0) {
        total -= mGrain.Count;
        if (total >= 0) {
            mTotalTreasury -= (total * mGrain.Cost) / 1000;
            mGrain.Count += total;
        }
    }
}

void City::buyGrain(int amount) {
    if (amount >= 0) {
        mTotalTreasury -= (amount * mGrain.Cost) / 1000;
        mGrain.Count += amount;
    }
}

void City::buyLand(int amount) {
    if (amount > 0) {
        mLand.Count += amount;
        mTotalTreasury -= (int)((double)amount * mLand.Cost);
    }
}

void City::buyMarket() {
    mMarketPlaces.Count += 1;
    mMerchants.Count += 5;
    mTotalTreasury -= 1000;
    mPublicWorks += 1.0;
}

void City::buyMill() {
    mMills.Count += 1;
    mTotalTreasury -= 2000;
    mPublicWorks += 0.25;
}

void City::buyPalace() {
    mPalace.Count += 1;
    RandomGenerator generator;
    mNobles.Count += generator.withinRange(0, 2);
    mTotalTreasury -= 3000;
    mPublicWorks += 0.5;
}

void City::buySoldiers() {
    mSoldiers.Count += 20;
    mSerfs.Count -= 20;
    mTotalTreasury -= 500;
}

void City::setLand(int total) {
    mLand.Count = total;
}

void City::killSoldiers(int casualties) {
    mSoldiers.Count -= casualties;
}

void City::generateHarvest() {
    RandomGenerator random;
    mGrain.Harvest = (random.withinRange(1, 5) + random.withinRange(1, 6)) / 2;
    mGrain.Rats = random.withinRange(1, 50);
    mGrain.Count = ((mGrain.Count * 100) - (mGrain.Count * mGrain.Rats)) / 100;
}

void City::calculateRevenue(int playerLevel) {

    double temp = 150 - mSalesTax.Percentage - mCustomsTax.Percentage - mIncomeTax.Percentage;
    if (temp < 1.0) {
        temp = 1.0;
    }
    temp /= 100.0;

    mJusticeRev.Revenue = (mJusticeLevel * 300 - 500) * playerLevel;

    mCustomsTax.Revenue = mNobles.Count * 180 + mClergy.Count * 75 + mMerchants.Count * 20 * (int)temp;
    mCustomsTax.Revenue += (int)(mPublicWorks * 100.0);
    mCustomsTax.Revenue = (int)((mCustomsTax.Percentage / 100.0) * mCustomsTax.Revenue);

    mSalesTax.Revenue = mNobles.Count * 50 + mMerchants.Count * 25 + (int)mPublicWorks * 10;
    mSalesTax.Revenue *= (int)temp * (5 - mJusticeLevel) * mSalesTax.Percentage;
    mSalesTax.Revenue /= 200;

    mIncomeTax.Revenue = mNobles.Count * 250 + (int)mPublicWorks * 20 + (10 * mJusticeLevel * mNobles.Count * (int)temp);
    mIncomeTax.Revenue *= mIncomeTax.Percentage;
    mIncomeTax.Revenue /= 100;

    int totalRevs = mJusticeRev.Revenue + mCustomsTax.Revenue + mSalesTax.Revenue + mIncomeTax.Revenue;

    std::cout << "State revenues " << totalRevs << " gold florins\n";
    std::cout << "Income Tax: " << mIncomeTax.Revenue << "\n";
    std::cout << "Sales Tax: " << mSalesTax.Revenue << "\n";
    std::cout << "Customs Duty: " << mCustomsTax.Revenue << "\n";
    std::cout << "Justice: " << mJusticeRev.Revenue << "\n";

}

void City::addRevenue() {
    mTotalTreasury += mJusticeRev.Revenue + mCustomsTax.Revenue + mIncomeTax.Revenue + mSalesTax.Revenue;

    if (mTotalTreasury < 0) {
        mTotalTreasury = (int)((double)mTotalTreasury * 1.5);
    }

    // todo: check bankrupt
    // if (totalTreasury < (-1000 * playerLevel) { bankrupt}
}
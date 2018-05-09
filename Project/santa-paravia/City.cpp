#include "City.hpp"

void City::buyCathedral() {
    mCathedral += 1;
    RandomGenerator generator;
    mClergyCount += generator.withinRange(1, 6);
    mTotalTreasury -= 5000;
    mPublicWorks += 1.0;
}

void City::setGrain(int totalDesired) {
    if (totalDesired >= 0) {
        totalDesired -= mGrainReserve;
        if (totalDesired >= 0) {
            mTotalTreasury -= (totalDesired * mGrainPrice) / 1000;
            mGrainReserve += totalDesired;
        }
    }
}

void City::buyGrain(int amount) {
    if (amount >= 0) {
        mTotalTreasury -= (amount * mGrainPrice) / 1000;
        mGrainReserve += amount;
    }
}

void City::buyLand(int amount) {
    if (amount > 0) {
        mLandSize += amount;
        mTotalTreasury -= (int)((double)amount * mLandPrice);
    }
}

void City::buyMarket() {
    mMarketPlaceCount += 1;
    mMerchantCount += 5;
    mTotalTreasury -= 1000;
    mPublicWorks += 1.0;
}

void City::buyMill() {
    mMillCount += 1;
    mTotalTreasury -= 2000;
    mPublicWorks += 0.25;
}

void City::buyPalace() {
    mPalace += 1;
    RandomGenerator generator;
    mNobleCount += generator.withinRange(0, 2);
    mTotalTreasury -= 3000;
    mPublicWorks += 0.5;
}

void City::buySoldiers() {
    mSoldierCount += 20;
    mSerfCount -= 20;
    mTotalTreasury -= 500;
}

void City::setLand(int total) {
    mLandSize = total;
}

void City::killSoldiers(int casualties) {
    mSoldierCount -= casualties;
}

void City::generateHarvest() {
    RandomGenerator random;
    mHarvest = (random.withinRange(1, 5) + random.withinRange(1, 6)) / 2;
    mRatCount = random.withinRange(1, 50);
    mGrainReserve = ((mGrainReserve * 100) - (mGrainReserve * mRatCount)) / 100;
}

void City::addToTreasury(int amount) {
    mTotalTreasury += amount;
}

void City::deductFromTreasury(int amount) {
    mTotalTreasury -= amount;
}

void City::calculateRevenue(int playerLevel) {

    double temp = 150 - mSalesTax - mCustomsTax - mIncomeTax;
    if (temp < 1.0) {
        temp = 1.0;
    }
    temp /= 100.0;

    mJusticeRevenue = (mJusticeLevel * 300 - 500) * playerLevel;

    mCustomsTaxRevenue = mNobleCount * 180 + mClergyCount * 75 + mMerchantCount * 20 * (int)temp;
    mCustomsTaxRevenue += (int)(mPublicWorks * 100.0);
    mCustomsTaxRevenue = (int)((mCustomsTax / 100.0) * mCustomsTaxRevenue);

    mSalesTaxRevenue = mNobleCount * 50 + mMerchantCount * 25 + (int)mPublicWorks * 10;
    mSalesTaxRevenue *= (int)temp * (5 - mJusticeLevel) * mSalesTax;
    mSalesTaxRevenue /= 200;

    mIncomeTaxRevenue = mNobleCount * 250 + (int)mPublicWorks * 20 + (10 * mJusticeLevel * mNobleCount * (int)temp);
    mIncomeTaxRevenue *= mIncomeTax;
    mIncomeTaxRevenue /= 100;

    int totalRevs = mJusticeRevenue + mCustomsTaxRevenue + mSalesTaxRevenue + mIncomeTaxRevenue;

    std::cout << "State revenues " << totalRevs << " gold florins\n";
    std::cout << "Income Tax: " << mIncomeTaxRevenue << "\n";
    std::cout << "Sales Tax: " << mSalesTaxRevenue << "\n";
    std::cout << "Customs Duty: " << mCustomsTaxRevenue << "\n";
    std::cout << "Justice: " << mJusticeRevenue << "\n";

}

void City::addRevenue() {
    mTotalTreasury += mJusticeRevenue + mCustomsTaxRevenue + mIncomeTaxRevenue + mSalesTaxRevenue;

    if (mTotalTreasury < 0) {
        mTotalTreasury = (int)((double)mTotalTreasury * 1.5);
    }

    // todo: check bankrupt
    // if (totalTreasury < (-1000 * playerLevel) { bankrupt}
}
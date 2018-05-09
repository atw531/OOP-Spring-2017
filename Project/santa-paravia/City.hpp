#ifndef SANTA_PARAVIA_CITY_HPP
#define SANTA_PARAVIA_CITY_HPP


#include <string>
#include "RandomGenerator.hpp"
#include "Treasury.hpp"

class City {
public:
    City(std::string name)
            : mName(std::move(name)), mLandSize(10000), mCathedral(0), mPalace(0),
              mClergyCount(5), mSerfCount(2000), mNobleCount(4), mMerchantCount(25),
              mSoldierCount(25), mSoldierPay(1),
              mGrainReserve(5000), mGrainPrice(25), mGrainDemand(1), mRatCount(1), mHarvest(0),
              mJusticeLevel(2), mMarketPlaceCount(0), mMillCount(0),
              mPublicWorks(1.0), mLandPrice(10.0),
              mTotalTreasury(1000), mCustomsTax(25), mSalesTax(10), mIncomeTax(5) {

    }

    void buyCathedral();
    void setGrain(int totalDesired);
    void buyGrain(int amount);
    void buyLand(int amount);
    void buyMarket();
    void buyMill();
    void buyPalace();
    void buySoldiers();

    void setLand(int total);
    void killSoldiers(int casualties);

    void generateHarvest();

    void addToTreasury(int amount);
    void deductFromTreasury(int amount);
    void calculateRevenue(int playerLevel);
    void addRevenue();

    int getLandsize() { return mLandSize; }
    int getCathedralCount() { return mCathedral; }
    int getPalaceCount() { return mPalace; }
    int getClergyCount() { return mClergyCount; }
    int getMarketCount() { return mMarketPlaceCount; }
    int getMillCount() { return mMillCount; }
    int getMerchantCount() { return mMerchantCount; }
    int getNobleCount() { return mNobleCount; }
    int getSoldierCount() { return mSoldierCount; }
    int getSerfCount() { return mSerfCount; }
    int getJusticeLevel() { return mJusticeLevel; }
    int getTreasuryTotal() { return mTotalTreasury; }
    double getPublicWorks() { return mPublicWorks; }

private:
    std::string mName;

    int mLandSize;

    int mCathedral, mPalace;

    int mClergyCount, mSerfCount, mNobleCount, mMerchantCount;

    int mSoldierCount, mSoldierPay;

    int mGrainReserve, mGrainPrice, mGrainDemand, mRatCount, mHarvest;

    int mJusticeLevel;

    int mMarketPlaceCount, mMillCount;

    double mPublicWorks, mLandPrice;

    int mTotalTreasury;

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


#endif //SANTA_PARAVIA_CITY_HPP

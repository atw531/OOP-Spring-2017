#ifndef SANTA_PARAVIA_CITY_HPP
#define SANTA_PARAVIA_CITY_HPP


#include <string>
#include <iostream>
#include "RandomGenerator.hpp"
#include "Resource.hpp"
#include "Building.hpp"
#include "Citizen.hpp"
#include "RevenueStream.hpp"

class City {
public:
    City(std::string name)
            : mCityName(std::move(name)), mGrain(5000, 25), mLand(10000, 10.0),
              mCathedral(0), mPalace(0),
              mClergy(5), mSerfs(2000), mNobles(4), mMerchants(25), mSoldiers(25, 1),
              mJusticeLevel(2),
              mMarketPlaces(0), mMills(0),
              mPublicWorks(1.0),
              mTotalTreasury(1000), mCustomsTax(25), mSalesTax(10), mIncomeTax(5) {

    }

    // Getters
    int getSoldierCount() { return mSoldiers.Count; }
    int getLandSize() { return mLand.Count; }

    // Purchases and changes in quantity
    void buyCathedral();
    void setGrain(int total);
    void buyGrain(int amount);
    void setLand(int total);
    void buyLand(int amount);
    void buyMarket();
    void buyMill();
    void buyPalace();
    void buySoldiers();
    void killSoldiers(int casualties);

    // Grain Methods
    void generateHarvest();
    std::string getGrainStatus();
    void releaseGrain(int amount);
    void releaseMinGrain();
    void releaseMaxGrain();

    // Treasury Methods
    void calculateRevenue(int playerLevel);
    void addRevenue();
    void newLandAndGrainPrices();

protected:
    std::string mCityName;

    Grain mGrain;
    Land mLand;

    Building mCathedral, mPalace;

    Citizen mClergy, mNobles, mMerchants;
    Soldier mSoldiers;
    Serf mSerfs;

    Resource mMarketPlaces, mMills;

    Tax mCustomsTax, mSalesTax, mIncomeTax;
    RevenueStream mJusticeRev, mMarketRev, mMillRev;

    int mJusticeLevel;

    double mPublicWorks;

    int mTotalTreasury;

};

#endif //SANTA_PARAVIA_CITY_HPP

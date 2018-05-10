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

void City::serfsProcreating(double scale) {
    int absc;
    double ord;
    absc = (int)scale;
    ord = scale - (double)absc;
    RandomGenerator generator;
    mSerfs.New = (int)((((double)generator.withinRange(0, absc) + ord) * (double)mSerfs.Count) / 100.0);
    mSerfs.Count += mSerfs.New;
    //todo: print mSerfs.New serfs born this year
}

void City::serfsDecomposing(double scale) {
    int absc;
    double ord;
    absc = (int)scale;
    ord = scale - (double)absc;
    RandomGenerator generator;
    mSerfs.Dead = (int)((((double)generator.withinRange(0, absc) + ord) * (double)mSerfs.Count) / 100.0);
    mSerfs.Count -= mSerfs.Dead;
    //todo: print mSerfs.Dead serfs died this year
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

void City::newLandAndGrainPrices() {
    double x, y, random;
    int h;
    RandomGenerator gen;
    random = (double)((double)gen.generate() / (double)RAND_MAX);
    x = (double)mLand.Count;
    y = (((double)mSerfs.Count - (double)mMills.Count) * 100.0) * 5.0;

    if (y < 0.0) {
        y = 0.0;
    }
    if (y < x) {
        x = y;
    }

    y = (double)mGrain.Count * 2.0;
    if (y < x) {
        x = y;
    }

    y = (double)mGrain.Harvest + (random - 0.5);
    h = (int)(x*y);

    mGrain.Count += h;
    mGrain.Demand = (mNobles.Count * 100) + (mCathedral.Count * 40) + (mMerchants.Count * 30);
    mGrain.Demand += (mSoldiers.Count * 10) + (mSerfs.Count * 5);
    mLand.Cost = (3.0 * (double)mGrain.Harvest + (double)gen.withinRange(0, 6) + 10.0) / 10.0;

    if (h < 0) {
        h *= -1;
    }
    if (h < 1) {
        y = 2.0;
    } else {
        y = (double)((double)mGrain.Demand / (double)h);
        if (y > 2.0) {
            y = 2.0;
        }
    }

    if (y < 0.8) {
        y = 0.8;
    }

    mLand.Cost *= y;
    if (mLand.Cost < 1.0) {
        mLand.Cost = 1.0;
    }

    mGrain.Cost = (int)(((6.0 - (double)mGrain.Harvest) * 3.0 + (double)gen.withinRange(0, 5)
                         + (double)gen.withinRange(0, 5)) * 4.0 * y);

    mGrain.Rats = h;
}

std::string City::getGrainStatus() {
    switch (mGrain.Harvest) {
        case 1:
            return "Drought. Famine Threatens.";
            break;
        case 2:
            return "Bad Weather. Poor Harvest.";
            break;
        case 3:
            return "Normal Weather. Average Harvest.";
            break;
        case 4:
            return "Good Weather. Fine Harvest.";
            break;
        case 5:
            return "Excellent Weather. Great Harvest.";
            break;
        default:
            return "";
    }
}

void City::releaseGrain(int amount) {
    RandomGenerator generator;
    double xp, zp, x, z;
    std::string str;

    mSoldiers.Pay = mMarketRev.Revenue = 0;
    mSerfs.New = mSerfs.Fleeing = mSerfs.Transplanted = mSerfs.Dead = 0;
    mGrain.Count -= amount;

    z = (double)amount / (double)mGrain.Demand - 1.0;
    if (z > 0.0) {
        z /= 2.0;
    }
    if (z > 0.25) {
        z = z / 10.0 + 0.25;
    }

    zp = 50.0 - (double)mCustomsTax.Percentage - (double)mSalesTax.Percentage - (double)mIncomeTax.Percentage;
    if (zp < 0.0) {
        zp *= (double)mJusticeLevel;
    }
    zp /= 10.0;
    if (zp > 0.0) {
        zp += (3.0 - (double)mJusticeLevel);
    }

    z += (zp / 10.0);
    if (z > 0.5) {
        z = 0.5;
    }

    if (amount < mGrain.Demand - 1) {
        x = (double)mGrain.Demand - amount / (double)mGrain.Demand * 100.0 - 9.0;
        xp = x;
        if (x > 65.0) {
            x = 65.0;
        } else if (x < 0.0) {
            xp = 0.0;
            x = 0.0;
        }
        //todo: serfs procreating (3.0)
        //todo: serfs decomposing (xp + 8.0)
    } else {
        //todo: serfs procreating (7.0)
        //todo: serfs decomposing (3.0)
        if (mCustomsTax.Percentage + mSalesTax.Percentage < 35) {
            mMerchants.Count = generator.withinRange(0, 4);
        }
        if (mIncomeTax.Percentage < generator.withinRange(0, 28)) {
            mNobles.Count += generator.withinRange(0, 2);
            mClergy.Count += generator.withinRange(0, 3);
        }
        if (amount > (int)((double)mGrain.Demand * 1.3)) {
            zp = (double)mSerfs.Count / 1000.0;
            z = ((double)amount - (double)mGrain.Demand) / (double)mGrain.Demand * 10.0;
            z *= zp * (double)generator.withinRange(0, 25);
            z += (double)generator.withinRange(0, 40);
            mSerfs.Transplanted = (int)z;
            mSerfs.Count += mSerfs.Transplanted;
            //todo: print mSerfs.Transplanted serfs move to the city\n
            zp = z;
            z = (zp * (double)generator.generate()) / (double)RAND_MAX;
            if (z > 50.0) {
                z = 50.0;
            }
            mMerchants.Count += (int)z;
            mNobles.Count++;
            mClergy.Count += 2;
        }
    }

    if (mJusticeLevel > 2) {
        mJusticeRev.Revenue = mSerfs.Count / 100 * (mJusticeLevel - 2) * (mJusticeLevel - 2);
        mJusticeRev.Revenue = generator.withinRange(0, mJusticeRev.Revenue);
        mSerfs.Count -= mJusticeRev.Revenue;
        mSerfs.Fleeing = mJusticeRev.Revenue;
        //todo: print mSerfs.Fleeing serfs flee harsh justice\n
    }

    mMarketRev.Revenue = mMarketPlaces.Count * 75;
    if (mMarketRev.Revenue > 0) {
        mTotalTreasury += mMarketRev.Revenue;
        //todo: print Your market earned mMarketRev.Revenue florins\n
    }

    mMillRev.Revenue = mMills.Count * (55 + generator.withinRange(0, 250));
    if (mMillRev.Revenue > 0) {
        mTotalTreasury += mMillRev.Revenue;
        //todo: print Your woolen mill earned mMillRev.Revenue florins\n
    }

    mSoldiers.Pay = mSoldiers.Count * 3;
    mTotalTreasury -= mSoldiers.Pay;
    //todo: print You paid your soldiers mSoldiers.Pay florins\n
    //todo: print You have mSerfs.Count serfs in your city\n
    //todo: "Press Enter" - probably don't actually have to wait for this

    if (mLand.Count / 1000 > mSoldiers.Count) {
        //todo: mInvadeMe = true;
        //todo: return(3)
    } else if (mLand.Count / 500 > mSoldiers.Count) {
        //todo: mInvadeMe = true;
        //todo: return(3)
    }
    //todo: return(0)
}

void City::releaseMinGrain() {
    int amount = mGrain.Count / 5;
    releaseGrain(amount);
}

void City::releaseMaxGrain() {
    int amount = mGrain.Count - (mGrain.Count / 5);
    releaseGrain(amount);
}

void City::seizeAssets() {
    mMarketPlaces.Count = 0;
    mPalace.Count = 0;
    mCathedral.Count = 0;
    mMills.Count = 0;
    mLand.Count = 6000;
    mPublicWorks = 1.0;
    mTotalTreasury = 100;
}
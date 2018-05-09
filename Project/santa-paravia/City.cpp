#include "City.hpp"

void City::generateHarvest() {
    RandomGenerator random;
    mHarvest = (random.withinRange(1, 5) + random.withinRange(1, 6)) / 2;
    mRatCount = random.withinRange(1, 50);
    mGrainReserve = ((mGrainReserve * 100) - (mGrainReserve * mRatCount)) / 100;
}
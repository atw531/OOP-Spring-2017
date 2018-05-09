#include "Player.hpp"

int limit10(int num, int denom) {
    int val;
    val = num / denom;
    return(val > 10 ? 10 : val);
}

bool Player::checkIsDead(int currentYear) {
    return currentYear > mDeathYear;
}

bool Player::checkIsBankrupt() {
    if (mTotalTreasury < (-10000 * playerLevel())) {
        return true;
    }
}

/// Determines and sets the new title index for the player
/// \param difficultyLevel Difficulty level of the game
/// \return true if title changed, false otherwise
bool Player::determineNewTitle(int difficultyLevel) {
    int tally;
    tally = limit10(mMarketPlaces.Count, 1);
    tally += limit10(mPalace.Count, 1);
    tally += limit10(mCathedral.Count, 1);
    tally += limit10(mMills.Count, 1);
    tally += limit10(mTotalTreasury, 5000);
    tally += limit10(mLand.Count, 6000);
    tally += limit10(mMerchants.Count, 50);
    tally += limit10(mNobles.Count, 5);
    tally += limit10(mSoldiers.Count, 50);
    tally += limit10(mClergy.Count, 10);
    tally += limit10(mSerfs.Count, 2000);
    tally += limit10((int)(mPublicWorks * 100.0), 500);

    int tempNew = (tally / difficultyLevel) - mJusticeLevel;
    if (tempNew > 7) {
        tempNew = 7;
    } else if (tempNew < 0) {
        tempNew = 0;
    }

    if (tempNew > mTitleIndex) {
        mTitleIndex = tempNew;
        return true;
    }
    return false;
}

void Player::takeTurn() {

}
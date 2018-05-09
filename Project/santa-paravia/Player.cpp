#include "Player.hpp"

int limit10(int num, int denom) {
    int val;
    val = num / denom;
    return(val > 10 ? 10 : val);
}

/// Determines and sets the new title index for the player
/// \param difficultyLevel Difficulty level of the game
/// \return true if title changed, false otherwise
bool Player::determineNewTitle(int difficultyLevel) {
    int tally;
    tally = limit10(mCity->getMarketCount(), 1);
    tally += limit10(mCity->getPalaceCount(), 1);
    tally += limit10(mCity->getCathedralCount(), 1);
    tally += limit10(mCity->getMillCount(), 1);
    tally += limit10(mCity->getTreasuryTotal(), 5000);
    tally += limit10(mCity->getLandsize(), 6000);
    tally += limit10(mCity->getMerchantCount(), 50);
    tally += limit10(mCity->getNobleCount(), 5);
    tally += limit10(mCity->getSoldierCount(), 50);
    tally += limit10(mCity->getClergyCount(), 10);
    tally += limit10(mCity->getSerfCount(), 2000);
    tally += limit10((int)(mCity->getPublicWorks() * 100.0), 500);

    int tempNew = (tally / difficultyLevel) - mCity->getJusticeLevel();
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
#include "Game.hpp"

void Game::play() {
    // Start the game
    for (int i = 0; i < mPlayers.size(); i++) {
        Player* currentPlayer = mPlayers[i];
        //todo: play




        // End of turn, calculate new title
        if (currentPlayer->determineNewTitle(mDifficultyLevel)) {
            std::string tempStr = "";
            if (currentPlayer->getGender() == Male) {
                tempStr = MaleTitles[currentPlayer->getTitleIndex()];
            } else {
                tempStr = FemaleTitles[currentPlayer->getTitleIndex()];
            }

            std::cout << "Good news! You have achieved the rank of " << tempStr << "\n";
        }
    }
}

void Game::fight(Player* attacker, Player* defender) {
    RandomGenerator generator;

    int landTaken = (attacker->getSoldierCount() * 100) - (attacker->getLandSize() / 3);
    if (landTaken > defender->getLandSize() - 5000) {
        landTaken = (defender->getLandSize() - 5000) / 2;
    }

    attacker->setLandSize(attacker->getLandSize() + landTaken);
    defender->setLandSize(defender->getLandSize() - landTaken);

    std::string attackerTitle;
    if (attacker->getGender() == Male) {
        attackerTitle = MaleTitles[attacker->getTitleIndex()];
    } else {
        attackerTitle = FemaleTitles[attacker->getTitleIndex()];
    }
    std::cout << attackerTitle << attacker->getName();
    std::cout << " invades and seizes " << landTaken << " hectares of land!\n";

    int casualties = generator.withinRange(0, 40);
    if (casualties > defender->getSoldierCount() - 15) {
        casualties = defender->getSoldierCount() - 15;
    }
    defender->killSoldiers(casualties);

    std::string defenderTitle;
    if (defender->getGender() == Male) {
        defenderTitle = MaleTitles[defender->getTitleIndex()];
    } else {
        defenderTitle = FemaleTitles[defender->getTitleIndex()];
    }
    std::cout << defenderTitle << defender->getName();
    std::cout << " lost " << casualties << " soldiers in battle.\n";

}
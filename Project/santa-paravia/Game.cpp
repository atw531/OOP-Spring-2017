#include "Game.hpp"

void Game::play() {

    bool AllDead, Winner;
    AllDead = false;
    Winner = false;
    // Start the game
    for (int i = 0; i < mPlayers.size(); i++) {
        Player* currentPlayer = mPlayers[i];
        if (!currentPlayer->checkIsDead(mYear)) {
            currentPlayer->generateHarvest();
            currentPlayer->newLandAndGrainPrices();

            std::string currentTitle;
            if (currentPlayer->getGender() == Male) {
                currentTitle = MaleTitles[currentPlayer->getTitleIndex()];
            } else {
                currentTitle = FemaleTitles[currentPlayer->getTitleIndex()];
            }

            bool finished = false;
            while(!finished) {
                std::cout << "Year " << mYear << "\n";
                std::cout << currentTitle << " " << currentPlayer->getName() << "\n\n";

                std::cout << "Rats ate " << currentPlayer->mGrain.Rats << " of your grain reserves\n";
                std::cout << currentPlayer->getGrainStatus() << "\n\n";

                std::cout << "Grain Reserve: " << currentPlayer->mGrain.Count << "\n";
                std::cout << "Grain Demand: " << currentPlayer->mGrain.Demand << "\n";
                std::cout << "Grain Price: " << currentPlayer->mGrain.Cost << "\n";
                std::cout << "Land Price: " << currentPlayer->getLandPrice() << "\n";
                std::cout << "Treasury: " << currentPlayer->getTreasury() << "\n\n";

                std::cout << "You have " << currentPlayer->getLandSize() << " hectares of land.\n";
                std::cout << "1. Buy Grain, 2. Sell Grain, 3. Buy Land, 4. Sell Land, 5. Continue...\n";
                int input;
                std::cin >> input;
                int amount;
                switch (input) {
                    case 1:
                        std::cout << "How much grain do you want to buy?\n";
                        std::cin >> amount;
                        currentPlayer->buyGrain(amount);
                        break;
                    case 2:
                        std::cout << "How much grain do you want to sell?\n";
                        std::cin >> amount;
                        if (amount > currentPlayer->mGrain.Count) {
                            std::cout << "You don't have that much grain...\n";
                        } else {
                            //todo: sell grain
                        }
                        break;
                    case 3:
                        std::cout << "How much land do you want to buy?\n";
                        std::cin >> amount;
                        currentPlayer->buyLand(amount);
                        break;
                    case 4:
                        std::cout << "How much land do you want to sell?\n";
                        std::cin >> amount;
                        if (amount > currentPlayer->getLandSize()) {
                            std::cout << "You don't have that much land...\n";
                        } else {
                            //todo: sell land
                        }
                        break;
                    default:
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
                        finished = true;
                        break;
                }
            }

        }
        mYear++;
    }
}

void Game::fight(Player* attacker, Player* defender) {
    RandomGenerator generator;

    int landTaken = (attacker->getSoldierCount() * 100) - (attacker->getLandSize() / 3);
    if (landTaken > defender->getLandSize() - 5000) {
        landTaken = (defender->getLandSize() - 5000) / 2;
    }

    attacker->setLand(attacker->getLandSize() + landTaken);
    defender->setLand(defender->getLandSize() - landTaken);

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